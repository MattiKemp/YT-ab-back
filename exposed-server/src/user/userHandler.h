#ifndef userHandler_H
#define userHandler_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include "database/nb_db.h"
#include "parallel_hashmap/phmap.h"
#include "security/salting.h"

using namespace std;

struct UserCreds{
    string hash;
    string salt;
    unsigned long long time;
    // idk if this is the best way to do this :/
    UserCreds(): hash(""), salt(""), time(0){}
    UserCreds(string hash, string salt, unsigned long long time): hash(hash), salt(salt), time(time){}
    void set(string hash, string salt, unsigned long long time){this->hash = hash; this->salt = salt; this->time = time;};
};

class UserHandler{
private:
    phmap::parallel_flat_hash_map<string, UserCreds> userCache;
    std::shared_ptr<NbDB> db = std::shared_ptr<NbDB>(new NbDB("", "", "localhost", "adblock"));
public:
    UserHandler();
    bool addToCache(string username, string hash, string salt);
    bool createUser(string username, string password, string email);
    bool validate(string username, string password);
};


#endif
