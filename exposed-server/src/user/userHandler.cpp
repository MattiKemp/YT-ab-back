#include "userHandler.h"

UserHandler::UserHandler(){
    phmap::parallel_flat_hash_map<string, UserCreds> userCache;
    this->userCache = userCache;
}

bool UserHandler::addToCache(string username, string hash, string salt){
    UserCreds newCred = UserCreds(hash, salt, std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    auto func = [&newCred](UserCreds& v) { v = newCred; };
    return this->userCache.try_emplace_l(username, func);
}

bool UserHandler::createUser(string username, string password, string email){
    // maybe add caching here later, fuck it tho.
    string salt = get_salt(32);
    this->db->insertUserQuery(username, sha256_with_salt(password, salt), salt, email);
    return true;
}

bool UserHandler::validate(string username, string password){
    UserCreds val;
    auto func = [&val](UserCreds& v) { val = v; };
    if(this->userCache.if_contains(username, func)){
        return sha256_with_salt(password, val.salt) == val.hash;
    }
    vector<vector<DBValue>> info;
    this->db->userCredQuery(username, info);
    // add error checking here and in NbDB later.
    addToCache(username, info[0][0].strVal, info[0][1].strVal);
    return sha256_with_salt(password, info[0][1].strVal) == info[0][0].strVal;
}

