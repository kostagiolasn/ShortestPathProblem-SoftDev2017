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
    this->inQueueInternal = new int[this->graphSize];
    
    this->inQueueExternal = new int[this->graphSize];
    //Array Initialization
    int i;
    
    for(i = 0; i < this->graphSize; i++){
        this->inQueueInternal[i] = 0;
        this->inQueueExternal[i] = 0;
    }
    
    
}

BFS::~BFS(){
    delete[] this->inQueueInternal;
    delete[] this->inQueueExternal;
}

int BFS::findShortestPath(Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal, uint32_t startNodeId, uint32_t targetNodeId, int version){
    //cout << "eimai sth version " << version << endl;
    int edges = 0;
    uint32_t levelInt;
    uint32_t levelExt;
    Queue* neighborsExt = NULL;
    Queue* neighborsInt = NULL;
    int previousInternal = 0;
    int previousExternal = 0;
    this->queueExternal = new Queue();
    this->queueExternal->pushBack(startNodeId);
    this->queueExternal->setLevelBack(0);
    
    inQueueExternal[startNodeId] = version;
            
    this->queueInternal = new Queue();
    this->queueInternal->pushBack(targetNodeId);
    this->queueInternal->setLevelBack(0);
    inQueueInternal[targetNodeId] = version;
    
    while(!this->queueExternal->isEmpty() && !this->queueInternal->isEmpty()){
        levelExt = this->queueExternal->getLevelFront();
        uint32_t markedNodeExt = this->queueExternal->popFront();
        inQueueExternal[markedNodeExt] = version - 1;
        
        //cout << "ext: I popped " << markedNodeExt << endl;
        
        
        if(neighborsExt != NULL)
            delete neighborsExt;
        neighborsExt = indexExternal->getNeighborsOfNode(bufferExternal, markedNodeExt); 
        //cout << "ext " << endl;
        //neighborsExt->print();
        if(!neighborsExt->isEmpty()){
            int i;
            previousExternal++;

            while(!neighborsExt->isEmpty()){
                
                uint32_t neighbourExt = neighborsExt->popFront();
                if(neighbourExt != UINT32_T_MAX){
                    //cout << "ext: paei gia push " << neighbourExt << endl;
                    if(inQueueExternal[neighbourExt] != version){
                        queueExternal->pushBack(neighbourExt);
                        queueExternal->setLevelBack(levelExt + 1);

                        //cout << "ext: I pushed " << neighbourExt << " with level " << levelExt + 1 <<  endl;
                        inQueueExternal[neighbourExt] = version;
                        if(inQueueInternal[neighbourExt] == version){    
                            edges = queueExternal->getLevelOf(neighbourExt) + queueInternal->getLevelOf(neighbourExt);
                          
                            levelInt = levelExt = 0;
                            return edges;                  
                        }
                        
                    }
                }
            }
            
        }
        levelInt = this->queueInternal->getLevelFront();
        uint32_t markedNodeInt = this->queueInternal->popFront();
        inQueueInternal[markedNodeInt] = version - 1;

        //cout << "int: I popped " << markedNodeInt << endl;
        
        if(neighborsInt != NULL)
            delete neighborsInt;         
        neighborsInt = indexInternal->getNeighborsOfNode(bufferInternal, markedNodeInt);
        //cout << "int " << endl;
        //neighborsInt->print();
        if(!neighborsInt->isEmpty() ){
            int i;
            previousInternal++;
            //cout << "kanw expand gia " << markedNodeInt << endl;

            while(!neighborsInt->isEmpty()){
                
                uint32_t neighbourInt = neighborsInt->popFront();
                if(neighbourInt != UINT32_T_MAX){
                    //cout << "int: paei gia push " << neighbourInt << endl;

                    if(inQueueInternal[neighbourInt] != version){

                        queueInternal->pushBack(neighbourInt);
                        queueInternal->setLevelBack(levelInt + 1);

                        //cout << "int: I pushed " << neighbourInt << " with level " << levelInt + 1 <<  endl;
                        inQueueInternal[neighbourInt] = version;
                        if(inQueueExternal[neighbourInt] == version){
                            edges = queueExternal->getLevelOf(neighbourInt) + queueInternal->getLevelOf(neighbourInt);
                            
                            previousInternal = previousExternal = 0;
                            levelInt = levelExt = 0;
                            return edges;
                        }
                        
                    }
                }
            }
            
        }
        
    }
    //delete this->queueInternal;
    //delete this->queueExternal;
    
    //if(neighborsInt != NULL)
      //  delete neighborsInt;
   // if(neighborsExt != NULL)
       // delete neighborsExt;
    levelInt = levelExt = 0;

    return -1;
}