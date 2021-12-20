#include "MyController.hpp"

/* method for validating login credentials
   Input: username, password */
bool MyController::validateLogin(const oatpp::String& credentials) const{
    //cout << "validate endpoint" << endl;
    auto j = nlohmann::json::parse(credentials->c_str());
    cout << j["user"] << endl;
    string userTemp = j["user"];
    string passTemp = j["pass"];
    return false;
    //return UsersAsyncDBHandler::validate(this->db, j["user"], j["pass"]);
}

/* method for signing up a user (not implemented)
   Input: username, password, first name, last name, phone number */
bool MyController::signUp(const oatpp::String& info) const{
    //cout << "signup endpoint" << endl;
    auto j = nlohmann::json::parse(info->c_str());
    return true;
}

