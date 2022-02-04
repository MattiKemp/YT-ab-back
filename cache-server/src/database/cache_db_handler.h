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
    string adstamp;
    string name;
    bool remove;
    bool update;
    int upvotes;
    DBSyncQuery(): insert(false), adstamp(""), name(""), remove(false), update(false), upvotes(0) {}
    DBSyncQuery(bool insert, string adstamp, bool remove, bool update, int upvotes): insert(insert), adstamp(adstamp), remove(remove), update(update), upvotes(upvotes) {}
    // constructor for insert query
    DBSyncQuery(string adstamp, string name): insert(true), adstamp(adstamp), name(name), remove(false), update(false), upvotes(0) {}
    // constructor for remove query
    DBSyncQuery(bool remove): insert(false), adstamp(""), name(""), remove(remove), update(false), upvotes(0) {}
    // constructor for update query
    DBSyncQuery(bool update, int upvotes): insert(false), adstamp(""), name(""), remove(false), update(update), upvotes(upvotes) {}
    void print(){
        if(insert){
            cout << "insert: " << adstamp << endl; 
        }
        else if(remove){
            cout << "remove" << endl;
        }
        else if(update){
            cout << "update: " << upvotes << endl;
        }
    }
};

class CacheDBHandler{
private:
    phmap::parallel_node_hash_map<std::string, DBSyncQuery> queryQueue;
    std::shared_ptr<NbDB> db = std::shared_ptr<NbDB>(new NbDB("", "", "", ""));
public:
    CacheDBHandler();
    void close(){};
    void isConnected(){};
    
    void printQueue();

    void queueInsert(string url, string username, string adstamp, string name);
    void queueRemove(string url, string username);
    void queueUpvote(string url, string username, int upvote);

    void sync();
    
    void getTimestamps(string url, vector<Timestamp> &timestamps);
    // queries the database for all the timestamps, groups them by url, and sorts them
    // based on upvotes
    void getAllTimestamps(vector<pair<string, vector<Timestamp>>> &timestamps);
    


    // database access functions

    // database modifications functions
};

#endif
