#ifndef BFS_HPP
#define BFS_HPP

#define UINT32_T_MAX (0xffffffff)

#include <iostream>

#include "buffer.hpp"
#include "queue.hpp"
#include "index.hpp"


class BFS {
    
    private:
        bool* visitedInternal;      
        int* previousNodeInternal;
        
        bool* visitedExternal;
        int* previousNodeExternal;
        
        Queue* queueInternal;
        Queue* queueExternal;
        
        size_t graphSize;
    
    public:
        
        BFS(size_t);
        ~BFS();
        
        int findShortestPath(Index, Index, uint32_t, uint32_t);
        
};

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

int BFS::findShortestPath(Index indexInternal, Index indexExternal, uint32_t startNodeId, uint32_t targetNodeId){
    bool met = false;
    int edges = 0;
    //EXTERNAL
    this->queueExternal = new Queue();
    this->queueExternal->pushBack(startNodeId);
    
    visitedExternal[startNodeId - 1] = true;
    //cout << "External: I pushed " << startNodeId << endl;
    
    //INTERNAL
    this->queueInternal = new Queue();
    this->queueInternal->pushBack(targetNodeId);
    
    visitedInternal[targetNodeId - 1] = true;
    //cout << "Internal: I pushed " << targetNodeId << endl;
    
    
   
    while(!met){
        //if(queueExternal->isEmpty()){
           // cout << "There is no path between nodes " << startNodeId << " and " << targetNodeId << "." << endl;
            //return NULL;
        //}
        
        uint32_t markedNodeExt = this->queueExternal->popFront(queueExternal);
        //cout << "External: I popped " << markedNodeExt << endl;     
        //NodeList* neighborsExt = indexExternal.getListHead(indexExternal.getNodeIndex(), markedNodeExt);
        NodeList* neighborsExt = NULL;
     
        uint32_t markedNodeInt = this->queueInternal->popFront(queueInternal);
        //cout << "Internal: I popped " << markedNodeInt << endl;     
        //NodeList* neighborsInt = indexInternal.getListHead(indexInternal.getNodeIndex(), markedNodeInt);
        NodeList* neighborsInt = NULL;
        if(neighborsExt != NULL ){
            
            
            int i;
            for(i = 0; i < neighborsExt->get_neighborsSize(); i++){
                
                if(neighborsExt->get_neighborAtIndex(i) != UINT32_T_MAX){
                    uint32_t neighbourExt = neighborsExt->get_neighborAtIndex(i);
                   
                    if(visitedExternal[neighbourExt - 1] == false){
                        visitedExternal[neighbourExt - 1] = true;
                     
                        previousNodeExternal[neighbourExt - 1] = markedNodeExt;
                        queueExternal->pushBack(neighbourExt);
                        //cout << "External: I pushed " << neighbourExt << endl;
                        if(visitedInternal[neighbourExt - 1] == true){
                           
                            met = true;
                            
                            Queue* shortestPath = new Queue();
                            uint32_t current = neighbourExt;
                            shortestPath->pushFront(neighbourExt);
                            
                            while(previousNodeExternal[current - 1] != -1){
                                edges++;
                                shortestPath->pushFront(previousNodeExternal[current - 1]);
                                current = previousNodeExternal[current - 1];
                            }
                            
                            current = neighbourExt;
                            //shortestPath->pushFront(neighbourExt);
                            
                            while(previousNodeInternal[current - 1] != -1){
                                edges++;
                                 shortestPath->pushBack(previousNodeInternal[current - 1]);
                                 current = previousNodeInternal[current - 1];
                            }
                            return edges;
                            
                        }
                    
                    }
                }
            }
        }else
            break;
        
        if(neighborsInt != NULL ){
            
            
            int i;
            for(i = 0; i < neighborsInt->get_neighborsSize(); i++){
                
                if(neighborsInt->get_neighborAtIndex(i) != UINT32_T_MAX){
                    uint32_t neighbourInt = neighborsInt->get_neighborAtIndex(i);
                   
                    if(visitedInternal[neighbourInt - 1] == false){
                        visitedInternal[neighbourInt - 1] = true;
                     
                        previousNodeInternal[neighbourInt - 1] = markedNodeInt;
                        queueInternal->pushBack(neighbourInt);
                        //cout << "Internal: I pushed " << neighbourInt << endl;
                        if(visitedExternal[neighbourInt - 1] == true){
                            
                            met = true;
                            
                            Queue* shortestPath = new Queue();
                            uint32_t current = neighbourInt;
                            shortestPath->pushBack(neighbourInt);
                            
                            while(previousNodeInternal[current - 1] != -1){
                                edges++;
                                 shortestPath->pushBack(previousNodeInternal[current - 1]);
                                 current = previousNodeInternal[current - 1];
                            }
                            
                            current = neighbourInt;
                            
   
                            while(previousNodeExternal[current - 1] != -1){
                                edges++;
                                 shortestPath->pushFront(previousNodeExternal[current - 1]);
                                 current = previousNodeExternal[current - 1];
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

#endif /* BFS_HPP */

