#include "MyController.hpp"

// endpoint function to print the linked list
string MyController::printLL(const oatpp::String& credentials) const{
    this->cache->printLinkedList();
    return "{\"valid\":\"YES\"}";
}

// endpoint to add a timestamp to the cache and queue up the timestamp for the database
string MyController::createTS(const oatpp::String& credentials) const{
    cout << "create timestamp endpoint" << endl;
    auto j = nlohmann::json::parse(credentials->c_str());
    cout << j.dump() << endl;
//    string times = j["adTimes"];
//    Timestamp new_timestamp = Timestamp();
//    new_timestamp.up_votes = 10;
//    for(int i = 0; i < times.size(); i+=2){
//        new_timestamp.ad_times.push_back(make_pair(times[i], times[i+1]));
//    }
//    new_timestamp.ad_times = times;
    // not sure if we should set null pointers for the initial prev and next :/
    // need to look more into this.
//    Node * temp = new Node();
//    temp->timestamps.push_back(new_timestamp);
    this->cache->addNB(j["url"], j["user"], j["adTimes"]);
    //this->cache->addBlocking(j["url"], temp);
    return "{\"valid\":\"YES\"}";
}

string MyController::removeTS(const oatpp::String& credentials) const{
    cout << "remove timestamp endpoint" << endl;
    auto j = nlohmann::json::parse(credentials->c_str());
    cout << j.dump() << endl;
    this->cache->removeNB(j["url"], j["user"]);
    return "{\"valid\":\"YES\"}";
}

// this is basically get top timestamp
string MyController::getTS(const oatpp::String& credentials) const{
    cout << "get timestamp endpoint" << endl;
    auto j = nlohmann::json::parse(credentials->c_str());
    cout << j.dump() << endl;
    nlohmann::json result;
    //result["adTimes"] = this->cache->getTimestampBlocking(j["url"]).ad_times;
    result["adTimes"] = this->cache->getTimestampNB(j["url"]).ad_times;
    return result.dump();
}
