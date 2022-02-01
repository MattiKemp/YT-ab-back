#ifndef CCApiClient_hpp
#define CCApiClient_hpp

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Api client for the async endpoints. All endpoints are subject to change. 
 */
class CCApiClient : public oatpp::web::client::ApiClient {
  
  API_CLIENT_INIT(CCApiClient)

  API_CALL("POST", "/print", printLL, BODY_STRING(String, body))
  
  API_CALL("POST", "/timestamp-create", timestampCreate, BODY_STRING(String, body))

  API_CALL("POST", "/timestamp-remove", timestampRemove, BODY_STRING(String, body))

  API_CALL("POST", "/timestamp-get", timestampGet, BODY_STRING(String, body))
  
};

#include OATPP_CODEGEN_END(ApiClient)

#endif /* ApiClient_hpp */
