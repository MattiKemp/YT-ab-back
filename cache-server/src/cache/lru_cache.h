#ifndef lru_cache_H
#define lru_cache_H

#include <string>
#include <iostream>
#include "parallel_hashmap/phmap.h"
#include "linked_list.h"
#include "database/cache_db_handler.h"

using namespace std;

class LRUCache{
private:
    // make this one bucket so the whole map gets locked during access.
    phmap::parallel_node_hash_map<string, Node*> nodes;
    LinkedList linked_list;
    std::shared_ptr<CacheDBHandler> dbHandler = std::shared_ptr<CacheDBHandler>(new CacheDBHandler());
public:
    // all blocking functions
    LRUCache();
    void addBlocking(string url, Node * node);
    void removeBlocking(string url);
    Timestamp getTimestampBlocking(string url);
    Timestamp getTopTimeStampBlocking(string url);
    vector<Timestamp> getTopNTimeStampsBlocking(string url, int n);
    vector<Timestamp> getAllTimeStampsBlocking(string url);
    // for testing, blocking
    void printLinkedList();

    // non-blocking functions
    //void addNB(string url, string username, Node * node);
    void addNB(string url, string username, string adstamp);
    bool removeNB(string url, string username);
    Timestamp getTimestampNB(string url);
    Timestamp getTopTimeStampNB(string url);

};

#endif
