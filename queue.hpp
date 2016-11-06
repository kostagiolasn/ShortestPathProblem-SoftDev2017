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


#endif /* QUEUE_HPP */

