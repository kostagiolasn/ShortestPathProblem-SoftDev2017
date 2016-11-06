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
    this->previousNodeInternal = new int[this->graphSize];
    
    this->visitedExternal = new bool[this->graphSize];
    this->previousNodeExternal = new int[this->graphSize];
    //Array Initialization
    int i;
    
    for(i = 0; i < this->graphSize; i++){
        this->visitedInternal[i] = false;
        this->previousNodeInternal[i] = -1;
        
        this->visitedExternal[i] = false;
        this->previousNodeExternal[i] = -1;
    }
    
    
}

BFS::~BFS(){
    delete this->visitedInternal;
    delete this->previousNodeInternal;
    
    delete this->visitedExternal;
    delete this->previousNodeExternal;
}

int BFS::findShortestPath(Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal, uint32_t startNodeId, uint32_t targetNodeId){
    bool met = false;
    int edges = 0;
    //EXTERNAL
    
    this->queueExternal = new Queue();
    this->queueExternal->pushBack(startNodeId);
    //cout << "mphka"<< endl;
    visitedExternal[startNodeId] = true;
    cout << "External: I pushed " << startNodeId << endl;
    
    //INTERNAL
    this->queueInternal = new Queue();
    this->queueInternal->pushBack(targetNodeId);
    
    visitedInternal[targetNodeId] = true;
    cout << "Internal: I pushed " << targetNodeId << endl;
    
    
   
   while(!met){
        //if(queueExternal->isEmpty()){
           // cout << "There is no path between nodes " << startNodeId << " and " << targetNodeId << "." << endl;
            //return NULL;
        //}
        
        uint32_t markedNodeExt = this->queueExternal->popFront();
        cout << "External: I popped " << markedNodeExt << endl;     
        Queue* neighborsExt = indexExternal->getNeighborsOfNode(bufferExternal, markedNodeExt);
        //cout << "i got ext neigh " << neighborsExt->isEmpty() << endl;
        //neighborsExt->print();
        
        uint32_t markedNodeInt = this->queueInternal->popFront();
        cout << "Internal: I popped " << markedNodeInt << endl;     
        Queue* neighborsInt = indexInternal->getNeighborsOfNode(bufferInternal, markedNodeInt);
        //cout << "i got int neigh" << endl;
        //neighborsInt->print();
        
        if(!neighborsExt->isEmpty()){
            //cout << "Ext: " << markedNodeExt << " has neighs" << endl;
            
            int i;
            while(!neighborsExt->isEmpty()){
                uint32_t neighbourExt = neighborsExt->popFront();
                if(neighbourExt != UINT32_T_MAX){
                    if(visitedExternal[neighbourExt] == false){
                        visitedExternal[neighbourExt] = true;
                     
                        previousNodeExternal[neighbourExt] = markedNodeExt;
                        queueExternal->pushBack(neighbourExt);
                        cout << "External: I pushed " << neighbourExt << endl;
                        if(visitedInternal[neighbourExt] == true){
                           
                            met = true;
                            
                            Queue* shortestPath = new Queue();
                            uint32_t current = neighbourExt;
                            shortestPath->pushFront(neighbourExt);
                            
                            while(previousNodeExternal[current] != -1){
                                edges++;
                                shortestPath->pushFront(previousNodeExternal[current]);
                                current = previousNodeExternal[current];
                            }
                            
                            current = neighbourExt;
                            //shortestPath->pushFront(neighbourExt);
                            
                            while(previousNodeInternal[current] != -1){
                                edges++;
                                 shortestPath->pushBack(previousNodeInternal[current]);
                                 current = previousNodeInternal[current];
                            }
                            return edges;
                            
                        }
                    }
                }
            }
        }else
            break;
        
        if(!neighborsInt->isEmpty() ){
            
            
            int i;
            while(!neighborsInt->isEmpty()){
                uint32_t neighbourInt = neighborsInt->popFront();
                if(neighbourInt != UINT32_T_MAX){
                   
                   
                    if(visitedInternal[neighbourInt] == false){
                        visitedInternal[neighbourInt] = true;
                     
                        previousNodeInternal[neighbourInt] = markedNodeInt;
                        queueInternal->pushBack(neighbourInt);
                        cout << "Internal: I pushed " << neighbourInt << endl;
                        if(visitedExternal[neighbourInt] == true){
                            
                            met = true;
                            
                            Queue* shortestPath = new Queue();
                            uint32_t current = neighbourInt;
                            shortestPath->pushBack(neighbourInt);
                            
                            while(previousNodeInternal[current] != -1){
                                edges++;
                                 shortestPath->pushBack(previousNodeInternal[current]);
                                 current = previousNodeInternal[current];
                            }
                            
                            current = neighbourInt;
                            
   
                            while(previousNodeExternal[current] != -1){
                                edges++;
                                 shortestPath->pushFront(previousNodeExternal[current]);
                                 current = previousNodeExternal[current];
                            }
                            return edges;
                        }
                    
                    }
                }
            }
        }else
            break;
    }
    
    return -1;
}