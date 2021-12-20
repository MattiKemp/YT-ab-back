#include "MyController.hpp"

/* method for validating login credentials
   Input: username, password */
string MyController::validateLogin(const oatpp::String& credentials) const{
    //cout << "validate endpoint" << endl;
    auto j = nlohmann::json::parse(credentials->c_str());
    cout << j["user"] << endl;
    if(this->uHand->validate(j["user"], j["pass"])){
        return "{\"valid\":\"YES\"}";
    }
    return "{\"valid\":\"NO\"}";
    //return UsersAsyncDBHandler::validate(this->db, j["user"], j["pass"]);
}

/* method for signing up a user 
   Input: username, password, email */
string MyController::signUp(const oatpp::String& info) const{
    //cout << "signup endpoint" << endl;
    auto j = nlohmann::json::parse(info->c_str());
    this->uHand->createUser(j["user"], j["pass"], j["email"]);
    return "{\"valid\":\"YES\"}";
}

