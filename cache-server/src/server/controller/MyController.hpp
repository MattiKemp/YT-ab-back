#ifndef MyController_hpp
#define MyController_hpp
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include "server/clients/GraphApiClient.hpp"
#include "server/clients/CCApiClient.hpp"
#include "server/dto/MyDTOs.hpp"
#include "oatpp/web/client/RequestExecutor.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "database/nb_db.h"
#include "cache/lru_cache.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<--- Begin codegen

using namespace std;

/**
 * Class to control the async endpoints.
 */
class MyController : public oatpp::web::server::api::ApiController {
protected:
  typedef MyController __ControllerType;
public:
  OATPP_COMPONENT(std::shared_ptr<GraphApiClient>, gApiClient);
  OATPP_COMPONENT(std::shared_ptr<CCApiClient>, ccApiClient);
  std::shared_ptr<LRUCache> cache = std::shared_ptr<LRUCache>(new LRUCache());
  //std::shared_ptr<NbDB> db = std::shared_ptr<NbDB>(new NbDB("test", "Password22!", "localhost", "workoutdev"));
protected:
  MyController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    string printLL(const oatpp::String& credentials) const;
    string createTS(const oatpp::String& credentials) const;
    string removeTS(const oatpp::String& credentials) const;
    string getTS(const oatpp::String& credentials) const;
public:
  
  /**
   *  Inject @objectMapper component here as default parameter
   *  Do not return bare Controllable* object! use shared_ptr!
   */
  static std::shared_ptr<MyController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
                                                                    objectMapper)){
    return std::shared_ptr<MyController>(new MyController(objectMapper));
  }
 
  ADD_CORS(PrintLL, "*", "GET, POST, OPTIONS", "DNT, User-Agent, X-Requested-With, If-Modified-Since, Cache-Control, Content-Type, Range", "1728000")
  ENDPOINT_ASYNC("POST", "/print", PrintLL) {
    ENDPOINT_ASYNC_INIT(PrintLL)
    Action act() override {
      return request->readBodyToStringAsync().callbackTo(&PrintLL::returnResponse);
    }

    Action returnResponse(const oatpp::String& body){
      auto qResult = controller->printLL(body);
      auto response = controller->createResponse(Status::CODE_200, qResult);
      response->putHeaderIfNotExists("Access-Control-Allow-Methods", "GET, POST, PUT, OPTIONS, DELETE");
      response->putHeaderIfNotExists("Access-Control-Allow-Origin", "*");
      response->putHeaderIfNotExists("Access-Control-Max-Age", "1728000");
      return _return(response);
    }
  }; 

  ADD_CORS(TimestampCreate, "*", "GET, POST, OPTIONS", "DNT, User-Agent, X-Requested-With, If-Modified-Since, Cache-Control, Content-Type, Range", "1728000")
  ENDPOINT_ASYNC("POST", "/timestamp-create", TimestampCreate) {
    ENDPOINT_ASYNC_INIT(TimestampCreate)
    Action act() override {
      return request->readBodyToStringAsync().callbackTo(&TimestampCreate::returnResponse);
    }

    Action returnResponse(const oatpp::String& body){
      auto qResult = controller->createTS(body);
      auto response = controller->createResponse(Status::CODE_200, qResult);
      response->putHeaderIfNotExists("Access-Control-Allow-Methods", "GET, POST, PUT, OPTIONS, DELETE");
      response->putHeaderIfNotExists("Access-Control-Allow-Origin", "*");
      response->putHeaderIfNotExists("Access-Control-Max-Age", "1728000");
      return _return(response);
    }
  }; 

  ADD_CORS(TimestampRemove, "*", "GET, POST, OPTIONS", "DNT, User-Agent, X-Requested-With, If-Modified-Since, Cache-Control, Content-Type, Range", "1728000")
  ENDPOINT_ASYNC("POST", "/timestamp-remove", TimestampRemove) {
    ENDPOINT_ASYNC_INIT(TimestampRemove)
    Action act() override {
      return request->readBodyToStringAsync().callbackTo(&TimestampRemove::returnResponse);
    }

    Action returnResponse(const oatpp::String& body){
      auto qResult = controller->removeTS(body);
      auto response = controller->createResponse(Status::CODE_200, qResult);
      response->putHeaderIfNotExists("Access-Control-Allow-Methods", "GET, POST, PUT, OPTIONS, DELETE");
      response->putHeaderIfNotExists("Access-Control-Allow-Origin", "*");
      response->putHeaderIfNotExists("Access-Control-Max-Age", "1728000");
      return _return(response);
    }
  }; 

  ADD_CORS(TimestampGet, "*", "GET, POST, OPTIONS", "DNT, User-Agent, X-Requested-With, If-Modified-Since, Cache-Control, Content-Type, Range", "1728000")
  ENDPOINT_ASYNC("POST", "/timestamp-get", TimestampGet) {
    ENDPOINT_ASYNC_INIT(TimestampGet)
    Action act() override {
      return request->readBodyToStringAsync().callbackTo(&TimestampGet::returnResponse);
    }

    Action returnResponse(const oatpp::String& body){
      auto qResult = controller->getTS(body);
      auto response = controller->createResponse(Status::CODE_200, qResult);
      response->putHeaderIfNotExists("Access-Control-Allow-Methods", "GET, POST, PUT, OPTIONS, DELETE");
      response->putHeaderIfNotExists("Access-Control-Allow-Origin", "*");
      response->putHeaderIfNotExists("Access-Control-Max-Age", "1728000");
      return _return(response);
    }
  }; 

};

#include OATPP_CODEGEN_END(ApiController) //<--- End codegen

#endif /* MyController_hpp */
