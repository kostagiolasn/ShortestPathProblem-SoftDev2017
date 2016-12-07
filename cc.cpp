#include "cc.hpp"
#include "queue.hpp"


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
    delete this->updateIndex;
    free(this->ccindex);
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

void CC::findCC(Index* indexExternal, Index* indexInternal,  uint32_t nodeId, uint32_t ccId){
    bool* visited = new bool[this->graphSize];
    for(int i = 0; i < graphSize; i++){
        visited[i] = false;
    }
    cout << "desmeusa visited " << graphSize  << endl;
    Queue* queue = new Queue();
    queue->pushBack(nodeId);

    while(!queue->isEmpty()){
        nodeId = queue->popFront();
        this->ccindex[nodeId] = ccId;
       //cout << "ethesa " << nodeId << " -> " << ccId << endl;
        visited[nodeId] = true;
        Queue* neighbors = indexExternal->getNeighborsOfNode(nodeId);
        Queue* neighbors2 = indexInternal->getNeighborsOfNode( nodeId);

       cout << "phra geitones tou " << nodeId << endl;

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

void CC::findCCAll(Index* indexInternal, Index* indexExternal){
    uint32_t ccCounter = 0;
    for(uint32_t i = 0; i < this->graphSize; i++){

        if(indexExternal->isAllocated(i) != UINT32_T_MAX && !inComponent(i)){
            cout << i << endl;
            findCC(indexExternal, indexInternal, i, ccCounter);
            ccCounter++;
        }
    }
    this->ccCounter = ccCounter;
}

int CC::insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE, Index* indexExternal){

    cout << "!testing " << nodeIdS << " " << nodeIdE << endl;



    if(nodeIdS <= this->graphSize && this->ccindex[nodeIdS] != UINT32_T_MAX && nodeIdE > this->graphSize ){
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

    }else if(nodeIdS > this->graphSize && nodeIdE <= this->graphSize && this->ccindex[nodeIdE] != UINT32_T_MAX){
        if((this->ccindex = (uint32_t*) realloc(this->ccindex, sizeof(uint32_t) * this->graphSize * 2)) != NULL){
            for(int i = this->graphSize; i < this->graphSize*2; i++){
                this->ccindex[i] = UINT32_T_MAX;
            }

            this->graphSize = this->graphSize * 2;

            this->ccindex[nodeIdS] = this->ccindex[nodeIdE];
            return 0;
        }else
            return -1;

        //diplasiasmos

    }else if(nodeIdS < this->graphSize && nodeIdE < this->graphSize && this->ccindex[nodeIdS] != UINT32_T_MAX && this->ccindex[nodeIdE] != UINT32_T_MAX && this->ccindex[nodeIdS] != this->ccindex[nodeIdE]){
        updateIndex->insertNode(this->ccindex[nodeIdS], this->ccindex[nodeIdE]);
    }else if(nodeIdS > this->graphSize && nodeIdE > this->graphSize){
        if((this->ccindex = (uint32_t*) realloc(this->ccindex, sizeof(uint32_t) * this->graphSize * 2)) != NULL){
            for(int i = this->graphSize; i < this->graphSize*2; i++){
                this->ccindex[i] = UINT32_T_MAX;
            }
            this->graphSize = this->graphSize * 2;
            cout << "the counter is " << this->ccCounter<<  endl;
            this->ccindex[nodeIdS] = this->ccCounter;
            this->ccindex[nodeIdE] = this->ccCounter;
            this->ccCounter = this->ccCounter + 1;
            return 0;
        }else
            return -1;

        //diplasiasmos
    }
}
uint32_t CC::getCcCounter(){
    return this->ccCounter;
}
