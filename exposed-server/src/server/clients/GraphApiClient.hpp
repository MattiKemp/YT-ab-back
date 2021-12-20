#ifndef GraphApiClient_hpp
#define GraphApiClient_hpp

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Api client for the async endpoints. All endpoints are subject to change. 
 */
class GraphApiClient : public oatpp::web::client::ApiClient {
  
  API_CLIENT_INIT(GraphApiClient)
 
  // a lot of these can probably be simplified/optimized with query parameters instead of bodies.
  API_CALL("GET", "/get-user-graph", getUserGraph)
  
  API_CALL("POST", "/follow-total", postfollowingTotal, BODY_STRING(String, body))

  API_CALL("POST", "/follow-n", postfollowingN, BODY_STRING(String, body))
  
  API_CALL("POST", "/follow-all", postFollowingAll, BODY_STRING(String, body))

  API_CALL("POST", "/add-user", postAddUser, BODY_STRING(String, body))

  API_CALL("POST", "/remove-user", postRemoveUser, BODY_STRING(String, body))

  API_CALL("POST", "/add-user-relation", postAddUserRel, BODY_STRING(String, body))

  API_CALL("POST", "/remove-user-relation", postRemoveUserRel, BODY_STRING(String, body))

  API_CALL("GET", "/get-group-graph", getGroupGraph)
  
  API_CALL("POST", "/member-total", postMemberTotal, BODY_STRING(String, body))

  API_CALL("POST", "/member-n", postMemberN, BODY_STRING(String, body))

  API_CALL("POST", "/member-all", postMemberAll, BODY_STRING(String, body))

  API_CALL("POST", "/get-user-groups", postGetUserGroups, BODY_STRING(String, body))

};

#include OATPP_CODEGEN_END(ApiClient)

#endif /* ApiClient_hpp */
