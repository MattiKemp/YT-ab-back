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
  std::shared_ptr<NbDB> db = std::shared_ptr<NbDB>(new NbDB("test", "Password22!", "localhost", "workoutdev"));
protected:
  MyController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    bool validateLogin(const oatpp::String& credentials) const;
    bool signUp(const oatpp::String& info) const;
public:
  
  /**
   *  Inject @objectMapper component here as default parameter
   *  Do not return bare Controllable* object! use shared_ptr!
   */
  static std::shared_ptr<MyController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
                                                                    objectMapper)){
    return std::shared_ptr<MyController>(new MyController(objectMapper));
  }
 
  // see ApiClient for more info on each endpoint.

  ADD_CORS(Login, "*", "GET, POST, OPTIONS", "DNT, User-Agent, X-Requested-With, If-Modified-Since, Cache-Control, Content-Type, Range", "1728000")
  ENDPOINT_ASYNC("POST", "/login", Login) {
    ENDPOINT_ASYNC_INIT(Login)
    Action act() override {
      return request->readBodyToStringAsync().callbackTo(&Login::returnResponse);
    }

    Action returnResponse(const oatpp::String& body){
      bool validation = controller->validateLogin(body);
      //put this part inside validateLogin later, too lazy to do it rn lol.
      string qResult = "{\"valid\":\"NO\"}";
      if(validation){
        qResult = "{\"valid\":\"YES\"}";
      }
      auto response = controller->createResponse(Status::CODE_200, qResult);
      response->putHeaderIfNotExists("Access-Control-Allow-Methods", "GET, POST, PUT, OPTIONS, DELETE");
      response->putHeaderIfNotExists("Access-Control-Allow-Origin", "*");
      response->putHeaderIfNotExists("Access-Control-Max-Age", "1728000");
      return _return(response);
    }
  };
  
  ADD_CORS(SignUp, "*", "GET, POST, OPTIONS", "DNT, User-Agent, X-Requested-With, If-Modified-Since, Cache-Control, Content-Type, Range", "1728000")
  ENDPOINT_ASYNC("POST", "/signup", SignUp) {
    ENDPOINT_ASYNC_INIT(SignUp)
    Action act() override {
      return request->readBodyToStringAsync().callbackTo(&SignUp::returnResponse);
    }

    Action returnResponse(const oatpp::String& body){
      bool validation = controller->signUp(body);
      string qResult = "{\"valid\":\"NO\"}";
      if(validation){
        qResult = "{\"valid\":\"YES\"}";
      }
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
