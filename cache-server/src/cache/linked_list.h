#ifndef linked_list_H
#define linked_list_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Timestamp{
    // base 64 encoded times
    string ad_times;
    int up_votes;
    string username;
    string name;
    void print() {
        cout << up_votes << " | " << ad_times << " | " << username << endl;
        //for(auto it = this->ad_times.begin(); it != this->ad_times.end(); it++){
        //    cout << (*it).first << " | " << (*it).second << endl;
        //}
    }
    Timestamp(): ad_times(""), up_votes(0), username("empty-username"), name("empty-name"){}
    Timestamp(string ad_times, int up_votes, string username): ad_times(ad_times), up_votes(up_votes), username(username), name("empty-name"){}
};

struct Node{
    Node * prev;
    Node * next;
    vector<Timestamp> timestamps;
    Node(): prev(nullptr), next(nullptr), timestamps({}) {}
    // adds a timestamp in the correct position so that the vector is sorted
    // by descending upvotes.
    void addTimestamp(Timestamp& timestamp){
        // investigate where a while loop is faster in this scenario.
        // it certainly is easier to read.
        bool found = false;
        for(int i = 0; i < timestamps.size(); i++){
            if(timestamp.up_votes <= timestamps[i].up_votes){
                timestamps.insert(timestamps.begin() + i, timestamp);
                found = true;
                break;
            }
        }
        if(!found){
            timestamps.push_back(timestamp);
        }
    }
    void removeTimestamp() {}
};

class LinkedList{
private:
    Node * start;
    Node * end;
public:
    LinkedList();
    LinkedList(vector<Timestamp> timestamps);
    void addToBegin(Node * new_node);
    void removeFromEnd();
    void remove(Node * remove_node);
    void deleteNode(Node * delete_node);
    // for testing;
    void print();
};

#endif
