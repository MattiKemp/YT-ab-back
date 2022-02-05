#ifndef lru_cache_H
#define lru_cache_H

#include <string>
#include <iostream>
#include "parallel_hashmap/phmap.h"
#include "oatpp/core/async/Coroutine.hpp"
#include "oatpp/core/async/Executor.hpp"
#include "linked_list.h"
#include "database/cache_db_handler.h"

//#include OATPP_CODEGEN_BEGIN(LRUCache)

using namespace std;

class LRUCache{
public:
  //OATPP_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor);
  // this is gross, we should be using the above ^, but I can't
  // get it working :/
  std::shared_ptr<oatpp::async::Executor> executor = std::make_shared<oatpp::async::Executor>(
      1 /* Data-Processing threads */,
      1 /* I/O threads */,
      1 /* Timer threads */
    );
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

class DatabaseSyncer : public oatpp::async::Coroutine<DatabaseSyncer> {
private:
    std::shared_ptr<CacheDBHandler> dbHandler;
public:
    DatabaseSyncer(std::shared_ptr<CacheDBHandler> dbHandler): dbHandler(dbHandler) {}
    Action act() override {
        cout << "syncing database" << endl;
        dbHandler->sync();
        return waitRepeat(std::chrono::seconds(10));
    }
};

//#include OATPP_CODEGEN_END(LRUCache)

#endif
