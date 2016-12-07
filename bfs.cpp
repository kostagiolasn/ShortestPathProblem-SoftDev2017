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

int BFS::findShortestPath(Index* indexInternal, Index* indexExternal, uint32_t startNodeId, uint32_t targetNodeId, int version){
    int edges = 0;
    //cout << " version " << version << endl;
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
        //std::cout << "he" << std::endl;


//        int sizeExt = this->queueExternal->getSizeOfLevel(this->queueExternal->getLevelFront());
//        int sizeInt = this->queueInternal->getSizeOfLevel(this->queueExternal->getLevelFront());
        int sizeExt = indexExternal->getNeighborsOfLevel( this->queueExternal, this->queueExternal->getLevelFront());
        int sizeInt = indexInternal->getNeighborsOfLevel( this->queueInternal, this->queueInternal->getLevelFront());
        //cout << this->queueExternal->getIdFront() << " has " << sizeExt << endl;
        //cout << this->queueInternal->getIdFront() << " has  " << sizeInt << endl;

        if(neighborsExt != NULL)
            delete neighborsExt;
        neighborsExt = indexExternal->getNeighborsOfNode( this->queueExternal->getIdFront());



        if(neighborsInt != NULL)
            delete neighborsInt;
        neighborsInt = indexInternal->getNeighborsOfNode(this->queueInternal->getIdFront());
        //if(this->queueInternal->getIdFront() == 229111)
          //neighborsInt->print();
        bool internal = false;
        if(sizeInt > sizeExt)
            internal = true;



        if(internal && !this->queueExternal->isEmpty()){
            int i;
            previousExternal++;
            levelExt = this->queueExternal->getLevelFront();
            uint32_t markedNodeExt = this->queueExternal->popFront();
            inQueueExternal[markedNodeExt] = version;

            while(!neighborsExt->isEmpty()){

                uint32_t neighbourExt = neighborsExt->popFront();
                if(neighbourExt != UINT32_T_MAX){
                    if(inQueueExternal[neighbourExt] != version){
                        queueExternal->pushBack(neighbourExt);
                        queueExternal->setLevelBack(levelExt + 1);

                        inQueueExternal[neighbourExt] = version;
                        if(inQueueInternal[neighbourExt] == version){
                            edges = queueExternal->getLevelOf(neighbourExt) + queueInternal->getLevelOf(neighbourExt);

                            levelInt = levelExt = 0;
                            if(this->queueInternal != NULL)
                                delete this->queueInternal;
                            if(this->queueExternal != NULL)
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

        //cout << "int " << endl;
        //neighborsInt->print();
        if(!internal && !this->queueInternal->isEmpty() ){
            int i;
            //cout << "mphka gia to deutero" << endl;
            previousInternal++;
            levelInt = this->queueInternal->getLevelFront();
            uint32_t markedNodeInt = this->queueInternal->popFront();
            inQueueInternal[markedNodeInt] = version ;
            //cout << "Int: I popped " << markedNodeInt << endl;
            while(!neighborsInt->isEmpty()){
              //cout << "tha valw tous geitones tou " << endl;
                uint32_t neighbourInt = neighborsInt->popFront();
                if(neighbourInt != UINT32_T_MAX){

                    if(inQueueInternal[neighbourInt] != version){

                        queueInternal->pushBack(neighbourInt);
                        queueInternal->setLevelBack(levelInt + 1);
                        //cout << "Int: I pushed " << neighbourInt << endl;
                        inQueueInternal[neighbourInt] = version;
                        if(inQueueExternal[neighbourInt] == version){
                            edges = queueExternal->getLevelOf(neighbourInt) + queueInternal->getLevelOf(neighbourInt);

                            previousInternal = previousExternal = 0;
                            levelInt = levelExt = 0;
                            if(this->queueInternal != NULL)
                                delete this->queueInternal;
                            if(this->queueExternal != NULL)
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
    if(this->queueInternal != NULL)
        delete this->queueInternal;
    if(this->queueExternal != NULL)
        delete this->queueExternal;

    if(neighborsInt != NULL)
        delete neighborsInt;
    if(neighborsExt != NULL)
        delete neighborsExt;
    levelInt = levelExt = 0;

    return -1;
}
