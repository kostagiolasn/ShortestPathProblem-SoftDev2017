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
        size_t size;
       
    public:
        Queue();
        ~Queue();
        uint32_t popFront();
        void pushBack(uint32_t);
        void pushFront(uint32_t);
        void print();
        void printAsPath(uint32_t);
        bool isEmpty();
        uint32_t getQueueSize();
        size_t getSize();
        uint32_t getNthNeighbor(uint32_t);
};


Queue::Queue(){
    this->head = NULL;
    this->size = 0;
   
 }

Queue::~Queue(){
    while(this->head != NULL) {
        QueueNode * node = head->next;
        delete head;
        head = node;
    }
}

uint32_t Queue::popFront(){
    uint32_t returnValue;
    if(this->head != NULL){
        
        QueueNode* temp = this->head;
        
        this->head = this->head->next;
        returnValue = temp->nodeId;  
        delete temp;
        this->size--;

        return returnValue;
    }
}

void Queue::pushBack(uint32_t nodeId){
    
    if(this->head == NULL){
        this->head = new QueueNode();
        this->head->nodeId = nodeId;
        this->head->next = NULL;
        this->size++;
        
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
        this->size++;
    }
    
}

void Queue::pushFront(uint32_t nodeId){
    if(this->head == NULL){
        this->head = new QueueNode();
        this->head->nodeId = nodeId;
        this->head->next = NULL;
        this->size++;
    }else{
        QueueNode* newNode = new QueueNode();
        newNode->nodeId = nodeId;
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
        
    }
}

void Queue::print(){
    while(this->head != NULL){
        cout << this->head->nodeId << endl;
        this->head = this->head->next;
    }
}

void Queue::printAsPath(uint32_t targetNodeId){
    while(this->head != NULL){
        if(this->head->nodeId != targetNodeId)
            cout << this->head->nodeId << " -> ";
        else
            cout << this->head->nodeId;
        this->head = this->head->next;
    }
    cout << endl;
}

bool Queue::isEmpty(){
    if(this->head == NULL)
        return true;
    else 
        return false;
}

size_t Queue::getSize(){
    return this->size;
}

uint32_t Queue::getNthNeighbor(uint32_t n){
    while(this->head != NULL){
        if(this->head->nodeId == n)
            return this->head->nodeId;
        //cout << this->head->nodeId << endl;
        this->head = this->head->next;
    }
}
#endif /* QUEUE_HPP */

