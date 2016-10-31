#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

using namespace std;

struct QueueNode {
        uint32_t nodeId;
        QueueNode * next;
    };
    
class Queue{
    
    private:
        QueueNode* head;
       
    public:
        Queue();
        ~Queue();
        uint32_t popFront();
        void pushBack(uint32_t);
        void print();
};


Queue::Queue(){
    this->head = NULL;
    cout << "Queue is empty!" << endl;
 }

Queue::~Queue(){
    while(this->head != NULL) {
        QueueNode * node = head->next;
        delete head;
        head = node;
    }
}

uint32_t Queue::popFront(){
    if(this->head != NULL){
        QueueNode* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

void Queue::pushBack(uint32_t nodeId){
    if(this->head == NULL){
        this->head = new QueueNode();
        this->head->nodeId = nodeId;
        this->head->next = NULL;
        
    }else{
        
        QueueNode* temp = this->head;
        while(this->head->next != NULL){
            this->head = this->head->next;
        }
    
        QueueNode* newNode = new QueueNode();
        newNode->nodeId = nodeId;
        newNode->next = NULL;
        this->head->next = newNode;
        this->head = temp; 
    }
}

void Queue::print(){
    while(this->head != NULL){
        cout << this->head->nodeId << endl;
        this->head = this->head->next;
    }
}
#endif /* QUEUE_HPP */

