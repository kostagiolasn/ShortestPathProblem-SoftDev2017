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
    this->queueInternal = new ArrayQueue(graphSize);
    this->queueExternal = new ArrayQueue(graphSize);
    this->neighborsExt = new ArrayQueue(graphSize);
    this->neighborsInt = new ArrayQueue(graphSize);
    this->neighborsExtEdge = new ArrayQueue(graphSize);
    this->neighborsIntEdge = new ArrayQueue(graphSize);
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
    delete this->neighborsExt;
    delete this->neighborsInt;
    delete this->queueExternal;
    delete this->neighborsExtEdge;
    delete this->neighborsIntEdge;
    delete this->queueInternal;

}


int BFS::findShortestPath(Index* indexInternal, Index* indexExternal, uint32_t startNodeId, uint32_t targetNodeId, int version, int currVersion){
    int edges = 0;
  //  cout << " version " << version << " " << startNodeId << " " << targetNodeId << endl;

    uint32_t levelInt;
    uint32_t levelExt;
    this->queueExternal->Reset();
    this->queueInternal->Reset();
    int previousInternal = 0;
    int previousExternal = 0;
    this->queueExternal->Enqueue(startNodeId);
    this->queueExternal->setLevel(0, startNodeId);

    inQueueExternal[startNodeId] = version;


    this->queueInternal->Enqueue(targetNodeId);
    this->queueInternal->setLevel(0, targetNodeId);
    inQueueInternal[targetNodeId] = version;


    while(!this->queueExternal->IsEmpty() && !this->queueInternal->IsEmpty()){
      //  std::cout << "he" << std::endl;


//        int sizeExt = this->queueExternal->getSizeOfLevel(this->queueExternal->getLevelFront());
//        int sizeInt = this->queueInternal->getSizeOfLevel(this->queueExternal->getLevelFront());
        int sizeExt = indexExternal->getNeighborsOfLevel( this->queueExternal, this->queueExternal->getLevel(this->queueExternal->getIdFront()));
    //   std::cout << "hoss" << std::endl;

        int sizeInt = indexInternal->getNeighborsOfLevel( this->queueInternal, this->queueInternal->getLevel(this->queueInternal->getIdFront()));
    //   std::cout << "hoss3" << std::endl;

        //cout << this->queueExternal->getIdFront() << " has " << sizeExt << endl;
        //cout << this->queueInternal->getIdFront() << " has  " << sizeInt << endl;
      // cout << sizeExt << " " << sizeInt << endl;
        neighborsExt->Reset();
        indexExternal->getNeighborsOfNode(this->neighborsExt, this->queueExternal->getIdFront());
        if(currVersion != -1){
          neighborsExtEdge->Reset();
          indexExternal->getNeighborsPropertyOfNode(this->neighborsExtEdge, this->queueExternal->getIdFront());
        }


        neighborsInt->Reset();
        indexInternal->getNeighborsOfNode(this->neighborsInt, this->queueInternal->getIdFront());
        if(currVersion != -1){
          neighborsIntEdge->Reset();
          indexInternal>getNeighborsPropertyOfNode(this->neighborsIntEdge, this->queueInternal->getIdFront());
        }
        //if(this->queueInternal->getIdFront() == 229111)
          //neighborsInt->print();
        bool internal = false;
        if(sizeInt > sizeExt)
            internal = true;



        if(internal && !this->queueExternal->IsEmpty()){
            int i;
            previousExternal++;
            levelExt = this->queueExternal->getLevel(this->queueExternal->getIdFront());
            uint32_t markedNodeExt = this->queueExternal->Dequeue();
            inQueueExternal[markedNodeExt] = version;


            while(!neighborsExt->IsEmpty()){

                uint32_t neighbourExt = neighborsExt->Dequeue();
                uint32_t  neighbourExtEdge;
                if(currVersion != -1)
                  neighbourExtEdge = neighborsExtEdge->Dequeue();
                if(neighbourExt != UINT32_T_MAX){

                  if(currVersion != -1 && neighbourExtEdge == currVersion){
                    if(inQueueExternal[neighbourExt] != version){
                        queueExternal->Enqueue(neighbourExt);
                        queueExternal->setLevel(levelExt + 1, neighbourExt);


                        inQueueExternal[neighbourExt] = version;
                        if(inQueueInternal[neighbourExt] == version){
                            edges = queueExternal->getLevel(neighbourExt) + queueInternal->getLevel(neighbourExt);

                            levelInt = levelExt = 0;

                            return edges;

                        }

                      }
                    }
                }
            }

        }


        //cout << "int " << endl;
        //neighborsInt->print();
        if(!internal && !this->queueInternal->IsEmpty() ){
            int i;
            //cout << "mphka gia to deutero" << endl;
            previousInternal++;
            levelInt = this->queueInternal->getLevel(this->queueInternal->getIdFront());
            uint32_t markedNodeInt = this->queueInternal->Dequeue();
           //cout << "o " << markedNodeInt << "  exei level " << levelInt << " " << targetNodeId<< endl;

            inQueueInternal[markedNodeInt] = version ;
            while(!neighborsInt->IsEmpty()){
          //    cout << "tha valw tous geitones tou " << markedNodeInt << endl;

                uint32_t neighbourInt = neighborsInt->Dequeue();
                uint32_t neighbourIntEdge;
                if(currVersion != -1)
                  neighbourIntEdge = neighborsIntEdge->Dequeue();
                if(neighbourInt != UINT32_T_MAX){

                  if(currVersion != -1 && neighbourIntEdge == currVersion){
                    if(inQueueInternal[neighbourInt] != version){

                        queueInternal->Enqueue(neighbourInt);
                        queueInternal->setLevel(levelInt + 1, neighbourInt);

                        inQueueInternal[neighbourInt] = version;
                        if(inQueueExternal[neighbourInt] == version){
                            edges = queueExternal->getLevel(neighbourInt) + queueInternal->getLevel(neighbourInt);

                            previousInternal = previousExternal = 0;
                            levelInt = levelExt = 0;


                            return edges;
                        }
                      }
                    }
                }
            }

        }

    }



    return -1;
}
