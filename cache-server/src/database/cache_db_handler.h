#ifndef cache_db_hander_H
#define cache_db_handler_H

#include <string>
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include <vector>
#include "parallel_hashmap/phmap.h"
#include "database/nb_db.h"
#include "cache/linked_list.h"

using namespace std;

struct DBSyncQuery{
    bool insert;
    bool remove;
    bool update;
    int upvotes;
};

class CacheDBHandler{
private:
    phmap::parallel_node_hash_map<std::string, DBSyncQuery> queryQueue;
    std::shared_ptr<NbDB> db = std::shared_ptr<NbDB>(new NbDB("", "", "", ""));
public:
    CacheDBHandler();
    void close(){};
    void isConnected(){};

    void queueInsert(string url, string username, Node * node);
    void queueRemove(string url, string username);
    void queueUpvote(string url, string username, bool upvote);
    
    
    void getAllTimestamps(vector<pair<string, vector<Timestamp>>> &timestamps);
    


    // database access functions

    // database modifications functions
};

#endif
