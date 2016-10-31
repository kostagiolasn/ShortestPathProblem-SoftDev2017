#ifndef BFS_HPP
#define BFS_HPP

#include <iostream>

#include "buffer.hpp"
#include "queue.hpp"
#include "index.hpp"

class BFS {
    
    private:
        bool* visited;      
        int* previousNode;
        Queue* queue;
        size_t graphSize;
    
    public:
        
        BFS(size_t);
        ~BFS();
        
        uint32_t* findShortestPath(Buffer*, Index*, uint32_t, uint32_t);
    
};

BFS::BFS(size_t graphSize){
    this->graphSize = graphSize;
    this->queue = NULL;
    
    //Space Allocation
    this->visited = new bool[this->graphSize];
    this->previousNode = new int[this->graphSize];
    
    //Array Initialization
    int i;
    
    for(i = 0; i < this->graphSize; i++){
        this->visited[i] = false;
        this->previousNode[i] = -1;
    }
    
    
}

BFS::~BFS(){
    delete this->visited;
    delete this->previousNode;
}

uint32_t* BFS::findShortestPath(Buffer *buffer, Index *index, uint32_t startNodeId, uint32_t targetNodeId){
    //Enqueue startNodeId
    queue->pushBack(startNodeId);
    visited[startNodeId] = true;
    
    while(visited[targetNodeId] == false){
        uint32_t markedNode = queue->popFront();
        NodeList *neighbours = index->getListHead(*index, markedNode);
        
        int i;
        for(i = 0; i < 10; i++){
            if(neighbours[i] != UINT32_T_MAX){
                uint32_t neighbour = neighbours[i];
                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    previousNode[neighbour] = markedNode;
                    queue->pushBack(neighbour);
                    
                }
            }
        }
        
    }
    
}

#endif /* BFS_HPP */

