#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>
#include "bfs.hpp"

BFS::BFS(size_t graphSize){
    this->graphSize = graphSize;
    this->queueInternal = NULL;
    this->queueExternal = NULL;
    
    //Space Allocation
    this->visitedInternal = new bool[this->graphSize];
    this->inQueueInternal = new bool[this->graphSize];
    this->previousNodeInternal = new int[this->graphSize];
    
    this->visitedExternal = new bool[this->graphSize];
    this->inQueueExternal = new bool[this->graphSize];
    this->previousNodeExternal = new int[this->graphSize];
    //Array Initialization
    int i;
    
    for(i = 0; i < this->graphSize; i++){
        this->visitedInternal[i] = false;
        this->inQueueInternal[i] = false;
        this->previousNodeInternal[i] = 0;
        
        this->visitedExternal[i] = false;
        this->inQueueExternal[i] = false;
        this->previousNodeExternal[i] = 0;
    }
    
    
}

BFS::~BFS(){
    delete[] this->visitedInternal;
    delete[] this->previousNodeInternal;
    delete[] this->inQueueInternal;
    delete[] this->visitedExternal;
    delete[] this->previousNodeExternal;
    delete[] this->inQueueExternal;
}

int BFS::findShortestPath(Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal, uint32_t startNodeId, uint32_t targetNodeId){
    int edges = 0;
    Queue* neighborsExt = NULL;
    Queue* neighborsInt = NULL;
    this->queueExternal = new Queue();
    this->queueExternal->pushBack(startNodeId);
    inQueueExternal[startNodeId] = true;
            
    this->queueInternal = new Queue();
    this->queueInternal->pushBack(targetNodeId);
    inQueueInternal[targetNodeId] = true;
    
    while(!this->queueExternal->isEmpty() && !this->queueInternal->isEmpty()){
        uint32_t markedNodeExt = this->queueExternal->popFront();
        visitedExternal[markedNodeExt] = true;
        inQueueExternal[markedNodeExt] = false;
        
        
        
        if(neighborsExt != NULL)
            delete neighborsExt;
        neighborsExt = indexExternal->getNeighborsOfNode(bufferExternal, markedNodeExt); 
        
        if(!neighborsExt->isEmpty()){
            int i;
            while(!neighborsExt->isEmpty()){
                
                uint32_t neighbourExt = neighborsExt->popFront();
                if(neighbourExt != UINT32_T_MAX){
                    if(inQueueExternal[neighbourExt] == false){
                        previousNodeExternal[neighbourExt] = previousNodeExternal[markedNodeExt] + 1;
                        queueExternal->pushBack(neighbourExt);
                        inQueueExternal[neighbourExt] = true;
                        if(inQueueInternal[neighbourExt] == true){    
                            edges = previousNodeExternal[neighbourExt] + previousNodeInternal[neighbourExt]; 
                            delete this->queueInternal;
                            delete this->queueExternal;
            
                            if(neighborsInt != NULL)
                                delete neighborsInt;
                            if(neighborsExt != NULL)
                                delete neighborsExt;
                            return edges;                  
                        }
                        
                    }
                }
            }
            
        }
        
        uint32_t markedNodeInt = this->queueInternal->popFront();
        visitedInternal[markedNodeInt] = true;
        inQueueInternal[markedNodeInt] = false;
        
        
        if(neighborsInt != NULL)
            delete neighborsInt;         
        neighborsInt = indexInternal->getNeighborsOfNode(bufferInternal, markedNodeInt);
        if(!neighborsInt->isEmpty() ){
            int i;
            while(!neighborsInt->isEmpty()){
                
                uint32_t neighbourInt = neighborsInt->popFront();
                if(neighbourInt != UINT32_T_MAX){
                    if(inQueueInternal[neighbourInt] == false){
                        previousNodeInternal[neighbourInt] = previousNodeInternal[markedNodeInt] + 1;
                        queueInternal->pushBack(neighbourInt);
                        inQueueInternal[neighbourInt] = true;
                        if(inQueueExternal[neighbourInt] == true){
                            edges = previousNodeInternal[neighbourInt] + previousNodeExternal[neighbourInt];
                            delete this->queueInternal;
                            delete this->queueExternal;
            
                            if(neighborsInt != NULL)
                                delete neighborsInt;
                            if(neighborsExt != NULL)
                                delete neighborsExt;
                            return edges;
                        }
                        
                    }
                }
            }
            
        }
        
    }
    delete this->queueInternal;
    delete this->queueExternal;
    
    if(neighborsInt != NULL)
        delete neighborsInt;
    if(neighborsExt != NULL)
        delete neighborsExt;
    return -1;
}