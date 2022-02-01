#include "linked_list.h"

LinkedList::LinkedList(){
    this->start = nullptr;
    this->end = nullptr;
}

// not implemented
LinkedList::LinkedList(vector<Timestamp> timestamps){
    this->start = nullptr;
    this->end = nullptr;
}

void LinkedList::addToBegin(Node * new_node){
    if(this->end == nullptr){
        new_node->prev = nullptr;
        new_node->next = nullptr;
        this->start = new_node;
        this->end = new_node;
    }
    else{
        Node * temp = this->start;
        new_node->prev = nullptr;
        new_node->next = temp;
        temp->prev = new_node;
        this->start = new_node;
    }
}

void LinkedList::removeFromEnd(){
    if(this->start != nullptr){
        if(this->start == this->end){
            //delete this->start;
            this->start = nullptr;
            this->end = nullptr;
        }
        else{
            Node * temp = this->end->prev;
            temp->next = nullptr;
            //delete this->end;
            this->end = temp;
        }
    }
}

// not completed.
void LinkedList::remove(Node * remove_node){
    if(this->start == this->end){
        //delete remove_node;
        this->start = nullptr;
        this->end = nullptr;
    }
    else if(this->start == remove_node){
        Node * temp = this->start->next;
        //delete remove_node;
        temp->prev = nullptr;
        this->start = temp;
    }
    else if(this->end == remove_node){
        Node * temp = this->end->prev;
        //delete remove_node;
        temp->next = nullptr;
        this->end = temp;
    }
    else{
        remove_node->prev->next = remove_node->next;
        remove_node->next->prev = remove_node->prev;
        //delete remove_node;
    }
}

void LinkedList::deleteNode(Node * delete_node){
}

void LinkedList::print(){
    if(this->start == nullptr){
        cout << "empty list" << endl;
        return;
    }
    Node * head = this->start;
    while(head != nullptr){
        cout << "-----new node-----" << endl;
        for(auto it = head->timestamps.begin(); it != head->timestamps.end(); it++){
            (*it).print();
        }
        cout << endl;
        head = head->next;
    }
}
