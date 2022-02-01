#include "cache_db_handler.h"
#include <unordered_map>

CacheDBHandler::CacheDBHandler(){
}

void CacheDBHandler::queueInsert(string url, string username, Node * node){

    auto func = []() {};
//    this->queryQueue.try_emplace_l(url+username, func);
}

void CacheDBHandler::queueRemove(string url, string username){
    auto func = []() {};
//    this->queryQueue.try_emplace_l(url+username, func);
}

void CacheDBHandler::queueUpvote(string url, string username, bool upvote){
    auto func = []() {};
//    this->queryQueue.try_emplace_l(url+username, func);
}

void CacheDBHandler::getAllTimestamps(vector<pair<string, vector<Timestamp>>> &timestamps){
    vector<vector<DBValue>> stamps;
    this->db->adstampAllQuery(stamps);
    unordered_map<string, vector<Timestamp>> umap;
    for(int i = 0; i < stamps.size(); i++){
        if(umap.find(stamps[i][0].strVal) == umap.end()){
            vector<Timestamp> stampArr;
            stampArr.push_back(Timestamp(stamps[i][2].strVal, stamps[i][3].intVal, stamps[i][1].strVal));
            umap[stamps[i][0].strVal] = stampArr;
        }
        else{
            // Sort list based on upvotes in descending order
            // change to binary search insert later.
            // May also change based on rating algorithm.
            bool found = false;
            for(int j = 0; j < umap[stamps[i][0].strVal].size(); j++){
                if(umap[stamps[i][0].strVal][j].up_votes <= stamps[i][3].intVal){
                    umap[stamps[i][0].strVal].insert(umap[stamps[i][0].strVal].begin()+j, Timestamp(stamps[i][2].strVal, stamps[i][3].intVal, stamps[i][1].strVal));
                    found = true;
                    break;
                }
            }
            if(!found){
                umap[stamps[i][0].strVal].push_back(Timestamp(stamps[i][2].strVal, stamps[i][3].intVal, stamps[i][1].strVal));
            }
        }
    }
    for(auto itr = umap.begin(); itr != umap.end(); itr++){
        timestamps.push_back(make_pair(itr->first, itr->second));
    }
}
