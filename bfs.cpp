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
        this->previousNodeInternal[i] = 0;
        
        this->visitedExternal[i] = false;
        this->previousNodeExternal[i] = 0;
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
    //cout << "External: I pushed " << startNodeId << endl;
    
    //INTERNAL
    this->queueInternal = new Queue();
    this->queueInternal->pushBack(targetNodeId);
    
    visitedInternal[targetNodeId] = true;
    //cout << "Internal: I pushed " << targetNodeId << endl;
    
    
   
   while(!met){
        //if(queueExternal->isEmpty()){
           // cout << "There is no path between nodes " << startNodeId << " and " << targetNodeId << "." << endl;
            //return NULL;
        //}
        if(this->queueExternal->isEmpty())
           break;
        
        uint32_t markedNodeExt = this->queueExternal->popFront();
        
        cout << "External: I popped " << markedNodeExt << endl; 
        if(visitedInternal[markedNodeExt] == true){
                          
            edges = previousNodeExternal[markedNodeExt] + previousNodeInternal[markedNodeExt];
                          
            return edges;
                            
        }
            
        Queue* neighborsExt = indexExternal->getNeighborsOfNode(bufferExternal, markedNodeExt);
        //cout << "i got ext neigh " << neighborsExt->isEmpty() << endl;
        //neighborsExt->print();
        if(!neighborsExt->isEmpty()){
            //cout << "Ext: " << markedNodeExt << " has neighs" << endl;
            
            int i;
            while(!neighborsExt->isEmpty()){
                uint32_t neighbourExt = neighborsExt->popFront();
                if(neighbourExt != UINT32_T_MAX){
                    if(visitedExternal[neighbourExt] == false){
                        visitedExternal[neighbourExt] = true;
                        //visitedExternal[neighbourExt] = true;
                        //cout << "to marked ext: "<< markedNodeExt << " exei: "<< previousNodeExternal[markedNodeExt] <<endl;
                        previousNodeExternal[neighbourExt] = previousNodeExternal[markedNodeExt] + 1;
                        queueExternal->pushBack(neighbourExt);
                        cout << "External: I pushed " << neighbourExt << endl;
                        //if(visitedInternal[neighbourExt] == true){
                          
                               //edges = previousNodeExternal[neighbourExt] + previousNodeInternal[neighbourExt];
                          
                            //return edges;
                            
                        //}
                        
                    }
                }
            }
        }else
            break;
        cout << endl;
        if(this->queueInternal->isEmpty())
           break;
        uint32_t markedNodeInt = this->queueInternal->popFront();
        
        cout << "Internal: I popped " << markedNodeInt << endl;  
        if(visitedExternal[markedNodeInt] == true){
                            
                          
            edges = previousNodeInternal[markedNodeInt] + previousNodeExternal[markedNodeInt];
                            
            return edges;
        }
                    
           
        Queue* neighborsInt = indexInternal->getNeighborsOfNode(bufferInternal, markedNodeInt);
        //cout << "internal neighs are " <<endl;
        //neighborsInt->print();
        //cout << "i got int neigh" << endl;
        //neighborsInt->print();
        
        
        
        if(!neighborsInt->isEmpty() ){
            
            
            int i;
            while(!neighborsInt->isEmpty()){
                uint32_t neighbourInt = neighborsInt->popFront();
                if(neighbourInt != UINT32_T_MAX){
                   
                   
                    if(visitedInternal[neighbourInt] == false){
                        visitedInternal[neighbourInt] = true;
                     
                        previousNodeInternal[neighbourInt] = previousNodeInternal[markedNodeInt] + 1;
                        queueInternal->pushBack(neighbourInt);
                        cout << "Internal: I pushed " << neighbourInt << endl;
                        //if(visitedExternal[neighbourInt] == true){
                            
                          
                            //edges = previousNodeInternal[neighbourInt] + previousNodeExternal[neighbourInt];
                            
                            //return edges;
                        //}
                    }
                }
            }
        }else
            break;
        cout << endl;
    }
    
    return -1;
}