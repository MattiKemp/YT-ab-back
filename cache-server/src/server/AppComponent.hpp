#ifndef AppComponent_hpp
#define AppComponent_hpp

#include "clients/GraphApiClient.hpp"
#include "oatpp-libressl/server/ConnectionProvider.hpp"
#include "oatpp-libressl/client/ConnectionProvider.hpp"
#include "oatpp-libressl/Config.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/web/server/AsyncHttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/component.hpp"

/**
 *  Class which creates and holds Application components and registers components in oatpp::base::Environment
 *  Order of components initialization is from top to bottom.
 *  You shouldn't really need to modify this file.
 */
class AppComponent {
public:

   /**
   * Create Async Executor
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor)([] {
    return std::make_shared<oatpp::async::Executor>(
      9 /* Data-Processing threads */,
      4 /* I/O threads */,
      1 /* Timer threads */
    );
  }());
  
  /**
   *  Create ConnectionProvider component which listens on the port
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([] {
    // ssl cert file pathing
    OATPP_LOGD("oatpp::libressl::Config", "pem='%s'", CERT_PEM_PATH);
    OATPP_LOGD("oatpp::libressl::Config", "crt='%s'", CERT_CRT_PATH);
    auto config = oatpp::libressl::Config::createDefaultServerConfigShared(CERT_CRT_PATH, CERT_PEM_PATH /* private key */);

    /**
     * if you see such error:
     * oatpp::libressl::server::ConnectionProvider:Error on call to 'tls_configure'. ssl context failure
     * It might be because you have several ssl libraries installed on your machine.
     * Try to make sure you are using libtls, libssl, and libcrypto from the same package
     */

    return oatpp::libressl::server::ConnectionProvider::createShared(config, {"0.0.0.0", 9001, oatpp::network::Address::IP_4});
  }());
  
  /**
   *  Create Router component
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
    return oatpp::web::server::HttpRouter::createShared();
  }());
  
  /**
   *  Create ConnectionHandler component which uses Router component to route requests
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); // get Router component
    /* Async ConnectionHandler for Async IO and Coroutine based endpoints */
    OATPP_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor); // get Async executor component
    return oatpp::web::server::AsyncHttpConnectionHandler::createShared(router, executor);
  }());
  
  /**
   *  Create ObjectMapper component to serialize/deserialize DTOs in Contoller's API
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)([] {
    auto serializerConfig = oatpp::parser::json::mapping::Serializer::Config::createShared();
    auto deserializerConfig = oatpp::parser::json::mapping::Deserializer::Config::createShared();
    deserializerConfig->allowUnknownFields = false;
    auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared(serializerConfig, deserializerConfig);
    return objectMapper;
  }());
  
  /**
   *  Create ssl client connection provider
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, sslClientConnectionProvider) ("clientConnectionProvider", [] {
    auto config = oatpp::libressl::Config::createShared();
    tls_config_insecure_noverifycert(config->getTLSConfig());
    tls_config_insecure_noverifyname(config->getTLSConfig());
    return oatpp::libressl::client::ConnectionProvider::createShared(config, {"httpbin.org", 443});
  }());

  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, sslClientConnectionProviderGraph) ("clientConnectionProviderGraph", [] {
    auto config = oatpp::libressl::Config::createShared();
    tls_config_insecure_noverifycert(config->getTLSConfig());
    tls_config_insecure_noverifyname(config->getTLSConfig());
    return oatpp::libressl::client::ConnectionProvider::createShared(config, {"0.0.0.0", 8002});
  }());

  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, sslClientConnectionProviderCC) ("clientConnectionProviderCC", [] {
    auto config = oatpp::libressl::Config::createShared();
    tls_config_insecure_noverifycert(config->getTLSConfig());
    tls_config_insecure_noverifyname(config->getTLSConfig());
    return oatpp::libressl::client::ConnectionProvider::createShared(config, {"0.0.0.0", 8003});
  }());
  
  /**
   *  Create the async api client for the controller.
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<GraphApiClient>, gApiClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, connectionProvider, "clientConnectionProviderGraph");
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);
    auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
    return GraphApiClient::createShared(requestExecutor, objectMapper);
  }());
    
  OATPP_CREATE_COMPONENT(std::shared_ptr<CCApiClient>, ccApiClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, connectionProvider, "clientConnectionProviderCC");
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);
    auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
    return CCApiClient::createShared(requestExecutor, objectMapper);
  }());

};

#endif /* AppComponent_hpp */
