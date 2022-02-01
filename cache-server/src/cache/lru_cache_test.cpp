#include "lru_cache.h"

using namespace std;

// testing basic addition and removal when list is empty and will be empty after removal.
void emptyAddRemove(){
    LRUCache cache = LRUCache();
    cout << "testing empty add" << endl;
    Node * temp = new Node();
    Timestamp temp_stamp;
    temp_stamp.upvotes = 5;
    temp_stamp.ad_times.push_back(make_pair(10, 25));
    temp->timestamps.push_back(temp_stamp);
    cache.addBlocking("test", temp);
    cache.printLinkedList();
    cout << "testing empty remove" << endl;
    cache.removeBlocking("test");
    cache.printLinkedList();
}

void multAddRemove(){
    LRUCache cache = LRUCache();
    cout << "testing basic add" << endl;
    Node * temp = new Node();
    Timestamp temp_stamp;
    temp_stamp.upvotes = 5;
    temp_stamp.ad_times.push_back(make_pair(10, 25));
    temp->timestamps.push_back(temp_stamp);
    cache.addBlocking("test", temp);
    Node * temp2 = new Node();
    Timestamp temp_stamp2;
    temp_stamp2.upvotes = 2;
    temp_stamp2.ad_times.push_back(make_pair(8, 17));
    temp_stamp2.ad_times.push_back(make_pair(29, 65));
    temp2->timestamps.push_back(temp_stamp2);
    cache.addBlocking("test2", temp2);
    cache.printLinkedList();
    cout << "testing basic removal from end" << endl;
    cache.removeBlocking("test");
    cache.printLinkedList();
    cout << "testing basic readditon" << endl;
    temp = new Node();
    temp->timestamps.push_back(temp_stamp);
    cache.addBlocking("test", temp);
    cache.printLinkedList();
    cout << "testing basic removal from begin" << endl;
    cache.removeBlocking("test");
    cache.printLinkedList();
}

void multGet(){
    LRUCache cache = LRUCache();
    cout << "initial cache" << endl;
    Node * temp = new Node();
    Timestamp temp_stamp;
    temp_stamp.upvotes = 5;
    temp_stamp.ad_times.push_back(make_pair(10, 25));
    temp->timestamps.push_back(temp_stamp);
    cache.addBlocking("test", temp);
    Node * temp2 = new Node();
    Timestamp temp_stamp2;
    temp_stamp2.upvotes = 2;
    temp_stamp2.ad_times.push_back(make_pair(8, 17));
    temp_stamp2.ad_times.push_back(make_pair(29, 65));
    temp2->timestamps.push_back(temp_stamp2);
    cache.addBlocking("test2", temp2);
    Node * temp3 = new Node();
    Timestamp temp_stamp3;
    Timestamp temp_stamp4;
    temp_stamp3.upvotes = 2;
    temp_stamp3.ad_times.push_back(make_pair(2313, 3123));
    temp_stamp4.upvotes = 1;
    temp_stamp4.ad_times.push_back(make_pair(2311, 3120));
    temp3->timestamps.push_back(temp_stamp3);
    temp3->timestamps.push_back(temp_stamp4);
    cache.addBlocking("test3", temp3);
    cache.printLinkedList();
    cout << "get bottom node" << endl;
    cache.getTimestampBlocking("test").print();
    cache.printLinkedList();
    cout << "get middle node" << endl;
    cache.getTimestampBlocking("test3").print();
    cache.printLinkedList();
    cout << "get top node" << endl;
    cache.getTimestampBlocking("test3").print();
    cache.printLinkedList();
    cout << "get bottom node" << endl;
    cache.getTimestampBlocking("test2").print();
    cache.printLinkedList();
}

void emptyAddRemoveNB(){
    LRUCache cache = LRUCache();
    cout << "testing empty add" << endl;
    Node * temp = new Node();
    Timestamp temp_stamp;
    temp_stamp.upvotes = 5;
    temp_stamp.ad_times.push_back(make_pair(10, 25));
    temp->timestamps.push_back(temp_stamp);
    cache.addNB("test", temp);
    cache.printLinkedList();
    cout << "testing empty remove" << endl;
    cache.removeNB("test");
    cache.printLinkedList();
}

void multAddRemoveNB(){
    LRUCache cache = LRUCache();
    cout << "testing basic add" << endl;
    Node * temp = new Node();
    Timestamp temp_stamp;
    temp_stamp.upvotes = 5;
    temp_stamp.ad_times.push_back(make_pair(10, 25));
    temp->timestamps.push_back(temp_stamp);
    cache.addNB("test", temp);
    Node * temp2 = new Node();
    Timestamp temp_stamp2;
    temp_stamp2.upvotes = 2;
    temp_stamp2.ad_times.push_back(make_pair(8, 17));
    temp_stamp2.ad_times.push_back(make_pair(29, 65));
    temp2->timestamps.push_back(temp_stamp2);
    cache.addNB("test2", temp2);
    cache.printLinkedList();
    cout << "testing basic removal from end" << endl;
    cache.removeNB("test");
    cache.printLinkedList();
    cout << "testing basic readditon" << endl;
    temp = new Node();
    temp->timestamps.push_back(temp_stamp);
    cache.addNB("test", temp);
    cache.printLinkedList();
    cout << "testing basic removal from begin" << endl;
    cache.removeNB("test");
    cache.printLinkedList();
}

void multGetNB(){
    LRUCache cache = LRUCache();
    cout << "initial cache" << endl;
    Node * temp = new Node();
    Timestamp temp_stamp;
    temp_stamp.upvotes = 5;
    temp_stamp.ad_times.push_back(make_pair(10, 25));
    temp->timestamps.push_back(temp_stamp);
    cache.addNB("test", temp);
    Node * temp2 = new Node();
    Timestamp temp_stamp2;
    temp_stamp2.upvotes = 2;
    temp_stamp2.ad_times.push_back(make_pair(8, 17));
    temp_stamp2.ad_times.push_back(make_pair(29, 65));
    temp2->timestamps.push_back(temp_stamp2);
    cache.addNB("test2", temp2);
    Node * temp3 = new Node();
    Timestamp temp_stamp3;
    Timestamp temp_stamp4;
    temp_stamp3.upvotes = 2;
    temp_stamp3.ad_times.push_back(make_pair(2313, 3123));
    temp_stamp4.upvotes = 1;
    temp_stamp4.ad_times.push_back(make_pair(2311, 3120));
    temp3->timestamps.push_back(temp_stamp3);
    temp3->timestamps.push_back(temp_stamp4);
    cache.addNB("test3", temp3);
    cache.printLinkedList();
    cout << "get bottom node" << endl;
    cache.getTimestampNB("test").print();
    cache.printLinkedList();
    cout << "get middle node" << endl;
    cache.getTimestampNB("test3").print();
    cache.printLinkedList();
    cout << "get top node" << endl;
    cache.getTimestampNB("test3").print();
    cache.printLinkedList();
    cout << "get bottom node" << endl;
    cache.getTimestampNB("test2").print();
    cache.printLinkedList();
}

// blocking tests
//int main(){
//    cout << "------empty list add and del------" << endl;
//    emptyAddRemove();
//    cout << "------multiple add and del------" << endl;
//    multAddRemove();
//    cout << "------multiple get------" << endl;
//    multGet();
//    return 0;
//}

// non-blocking tests
int main(){
    cout << "------empty list add and del------" << endl;
    emptyAddRemoveNB();
    cout << "------multiple add and del------" << endl;
    multAddRemoveNB();
    cout << "------multiple get------" << endl;
    multGetNB();
    return 0;
}
