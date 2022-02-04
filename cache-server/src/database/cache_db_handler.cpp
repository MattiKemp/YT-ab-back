#include "cache_db_handler.h"
#include <unordered_map>

CacheDBHandler::CacheDBHandler(){
}

void CacheDBHandler::printQueue(){
    for (const auto& n : this->queryQueue){
        cout << n.first << ":" << endl;
        this->queryQueue[n.first].print();
    }
}

// I believe we need to take into account a scenario where
// someone has queued a remove, but then before the remove can be excuted,
// they insert. This will leave a situation where we have an insert and 
// there is already a url+username row in the database.
// Do later :p.
void CacheDBHandler::queueInsert(string url, string username, string adstamp, string name){
    //DBSyncQuery val = DBSyncQuery(true, false, false, 0);
    auto func = [](DBSyncQuery& v) {};
    this->queryQueue.try_emplace_l(url+username, func, true, adstamp, false, false, 0);
}

void CacheDBHandler::queueRemove(string url, string username){
    bool erase = false;
    auto func = [&erase](DBSyncQuery& v) {
        cout << "remove: query already exists:" << endl;
        v.print();
        if(v.insert){
            erase = true;
        }
        else{
            v.update = false;
            v.upvotes = 0;
            v.remove = true;
        }
    };
    this->queryQueue.try_emplace_l(url+username, func, true);
    auto erFunc = [](DBSyncQuery& v){ return true; };
    if(erase){
        this->queryQueue.erase_if(url+username, erFunc);
    }
}

void CacheDBHandler::queueUpvote(string url, string username, int upvote){
    auto func = [&upvote](DBSyncQuery& v) {
        cout << "update: query already exists:" << endl;
        v.print();
        if(!v.remove){
            v.upvotes = upvote;
        }
    };
    this->queryQueue.try_emplace_l(url+username, func, true, upvote);
}

// synchronize the cache with the database by using the sync queries
void CacheDBHandler::sync(){
    // not sure if this will fuck up the queue bc it is blocking.
    // add memory reserving later.
    string query = "BEGIN; ";
    for (const auto& n : this->queryQueue){
        cout << n.first << ":" << endl;
        this->queryQueue[n.first].print();
        DBSyncQuery curr = this->queryQueue[n.first];
        if(curr.insert){
            query += "INSERT INTO adstamp (url, username, times, upvotes, name) VALUES ('" + n.first.substr(0, 11) + "', '" + n.first.substr(11) + "', '" + curr.adstamp + "', 0, '" + curr.name + "'; ";
        }
        else if(curr.remove){
            query += "DELETE FROM adstamp WHERE url = '" + n.first.substr(0, 11) + "', username = '" + n.first.substr(11) + "'; ";
        }
        else{
            query += "UPDATE adstamp SET upvotes = " + to_string(curr.upvotes) + " WHERE url = '" + n.first.substr(0,11) + "', username = '" + n.first.substr(11) + "'; ";
        }
    }
    query += "COMMIT ;";
    this->queryQueue.clear();
    this->db->syncCacheDatabase(query);
}

void CacheDBHandler::getTimestamps(string url, vector<Timestamp> &timestamps){
    vector<vector<DBValue>> stamps;
    this->db->adstampsQuery(url, stamps);
    for(int i = 0; i < stamps.size(); i++){
        timestamps.push_back(Timestamp(stamps[i][2].strVal, stamps[i][3].intVal, stamps[i][1].strVal));
    }
}

// Need to change this later as we can't get all the timestamps starting out.
// Get first 10k highest upvoted, maybe add uses column to table.
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
