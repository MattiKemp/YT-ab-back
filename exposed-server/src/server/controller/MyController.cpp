#include "MyController.hpp"

/* method for validating login credentials
   Input: username, password */
string MyController::validateLogin(const oatpp::String& credentials) const{
    //cout << "validate endpoint" << endl;
    auto j = nlohmann::json::parse(credentials->c_str());
    //cout << j["user"] << endl;
    this->uHand->printCache();
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

string MyController::printLL(const oatpp::String& credentials) const{
    this->ccApiClient->printLL(credentials);
    return "{\"valid\":\"YES\"}";
}

string MyController::createTimestamp(const oatpp::String& credentials) const{
    cout << "create timestamp endpoint" << endl;
    auto j = nlohmann::json::parse(this->ccApiClient->timestampCreate(credentials)->readBodyToString()->c_str());
    cout << j.dump() << endl;
    return j.dump();
}

string MyController::removeTimestamp(const oatpp::String& credentials) const{
    cout << "remove timestamp endpoint" << endl;
    auto j = nlohmann::json::parse(this->ccApiClient->timestampRemove(credentials)->readBodyToString()->c_str());
    cout << j.dump() << endl;
    return j.dump();
}

string MyController::getTimestamp(const oatpp::String& credentials) const{
    cout << "get timestamp endpoint" << endl;
    auto j = nlohmann::json::parse(this->ccApiClient->timestampGet(credentials)->readBodyToString()->c_str());
    cout << j.dump() << endl;
    return j.dump();
}
