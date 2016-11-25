#include "cc.hpp"
#include "queue.hpp"
#include "index.hpp"

CC::CC(uint32_t graphSize){
    this->graphSize = graphSize;
    updateIndex = new UpdateIndex();
    this->ccCounter = 0;
    
    this->ccindex = (uint32_t*) malloc(sizeof(uint32_t)*graphSize);
    for(int i = 0; i < graphSize; i++){
        this->ccindex[i] = UINT32_T_MAX;
    }
}
CC::~CC(){
    //delete this->updateIndex;
    //free(this->ccindex);
}

void CC::print(){
    for(int i = 0; i < this->graphSize; i++){
        cout << i << " -> " << this->ccindex[i] << endl;
    }
    this->updateIndex->print();
}

void CC::insert(uint32_t nodeId, uint32_t componentId){
    this->ccindex[nodeId] = componentId;
}

bool CC::inComponent(uint32_t nodeId){
    if(this->ccindex[nodeId] == UINT32_T_MAX)
        return false;
    else 
        return true;
}

void CC::findCC(Index* indexExternal, Index* indexInternal, Buffer* bufferExternal, Buffer* bufferInternal, uint32_t nodeId, uint32_t ccId){
    bool* visited = new bool[this->graphSize];
    for(int i = 0; i < graphSize; i++){
        visited[i] = false;
    }
    Queue* queue = new Queue();
    queue->pushBack(nodeId);
    
    while(!queue->isEmpty()){
        nodeId = queue->popFront();
        this->ccindex[nodeId] = ccId;

        visited[nodeId] = true;
        Queue* neighbors = indexExternal->getNeighborsOfNode(bufferExternal, nodeId);
        Queue* neighbors2 = indexInternal->getNeighborsOfNode(bufferInternal, nodeId);
        
       
        while(!neighbors->isEmpty()){
            uint32_t neighbor = neighbors->popFront();
            if(!visited[neighbor]){
                queue->pushBack(neighbor);
            }
        }
        
         while(!neighbors2->isEmpty()){
            uint32_t neighbor = neighbors2->popFront();
            if(!visited[neighbor]){
                queue->pushBack(neighbor);
                
            }
        }
    }
    delete [] visited;
}

void CC::findCCAll(Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal){
    uint32_t ccCounter = 0;
    for(int i = 0; i < this->graphSize; i++){
        if(indexExternal->getNodeIndex()[i].getNodeId() != UINT32_T_MAX && !inComponent(i)){
            cout << i << endl;
            findCC(indexExternal, indexInternal, bufferExternal, bufferInternal, i, ccCounter);
            ccCounter++;
        }
    }
    this->ccCounter = ccCounter;
}

OK_SUCCESS CC::insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE, Index* indexExternal){
    cout << "testing " << nodeIdS << " " << nodeIdE << endl;
    if(this->ccindex[nodeIdS] != UINT32_T_MAX && nodeIdE > this->graphSize){
        cout << "to nodeIdE " << nodeIdE << " einai megalutero tou " << this->graphSize << endl;
        if((this->ccindex = (uint32_t*) realloc(this->ccindex, sizeof(uint32_t) * this->graphSize * 2)) != NULL){
            for(int i = this->graphSize; i < this->graphSize*2; i++){
                this->ccindex[i] = UINT32_T_MAX;
            }
            this->graphSize = this->graphSize * 2;
            this->ccindex[nodeIdE] = this->ccindex[nodeIdS];
            return 0;
        }else
            return -1;
        
        
        //diplasiasmos
    }else if(nodeIdS > this->graphSize && this->ccindex[nodeIdE] != UINT32_T_MAX){
        if((this->ccindex = (uint32_t*) realloc(this->ccindex, sizeof(uint32_t) * this->graphSize * 2)) != NULL){
            this->graphSize = this->graphSize * 2;

            this->ccindex[nodeIdS] = this->ccindex[nodeIdE];
            return 0;
        }else
            return -1;
        
        //diplasiasmos
    }else if(this->ccindex[nodeIdS] != UINT32_T_MAX && this->ccindex[nodeIdE] != UINT32_T_MAX && this->ccindex[nodeIdS] != this->ccindex[nodeIdE]){
        cout << "Edw " << this->ccindex[nodeIdE] << " graph size " << this->graphSize<< endl;
      updateIndex->insertNode(this->ccindex[nodeIdS], this->ccindex[nodeIdE]);  
    }else{
        //diplasiasmos
    }
}