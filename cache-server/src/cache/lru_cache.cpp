#include "lru_cache.h"

void LRUCache::printLinkedList(){
    this->linked_list.print();
}

LRUCache::LRUCache(){
    vector<pair<string, vector<Timestamp>>> stamps;
    this->dbHandler->getAllTimestamps(stamps);
    for(int i = 0; i < stamps.size(); i++){
        Node * newNode = new Node();
        newNode->timestamps = stamps[i].second;
        cout << stamps[i].first << endl;
        this->addBlocking(stamps[i].first, newNode);
        //this->addNB(stamps[i].first, newNode);
    }
    printLinkedList();
}

void LRUCache::addBlocking(string url, Node * node){
    this->linked_list.addToBegin(node);
    this->nodes[url] = node;
}

void LRUCache::removeBlocking(string url){
    this->linked_list.remove(this->nodes[url]);
    // probably need better memory management here
    this->nodes.erase(url);
}

Timestamp LRUCache::getTimestampBlocking(string url){
    if(this->nodes.contains(url)){
        this->linked_list.remove(nodes[url]);
        this->linked_list.addToBegin(nodes[url]);
        return nodes[url]->timestamps[0];
    }
    return Timestamp();
}

Timestamp LRUCache::getTopTimeStampBlocking(string url){
    return Timestamp();
}

vector<Timestamp> getTopNTimeStampsBlocking(string url, int n){
    return vector<Timestamp>();
}

vector<Timestamp> getAllTimeStampsBlocking(string url){
    return vector<Timestamp>();
}

void LRUCache::addNB(string url, Node * node){
    LinkedList ll = this->linked_list;
    //cout << node->timestamps[0].upvotes << endl;
    auto func = [&node, this](Node*& n) { node = n; };
    this->nodes.try_emplace_l(url, func);
    // idk why tf I have to do this, but the docs are ass for this library so I have no idea how to
    // 1. map a url to a an already existing Node in one call.
    // 2. How to get the function to call using try_emplace_l, or another function for insertion.
    auto func2 = [node, this](Node*& n) {n = node; this->linked_list.addToBegin(n); };
    this->nodes.modify_if(url, func2);
}

bool LRUCache::removeNB(string url){
    // might be a cleaner way to do this
    LinkedList ll = this->linked_list;
    auto func = [this](Node*& n) { this->linked_list.remove(n); return true; };
    return this->nodes.erase_if(url, func);
}

// pretty much currently does the samething as the below function.
Timestamp LRUCache::getTimestampNB(string url){
    Timestamp tstamp = Timestamp();
    auto func = [this, &tstamp](Node* n) { this->linked_list.remove(n); this->linked_list.addToBegin(n); tstamp = n->timestamps[0]; };
    nodes.if_contains(url, func);
    return tstamp;
}

Timestamp LRUCache::getTopTimeStampNB(string url){
}
