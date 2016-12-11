#include "cc.hpp"
#include "queue.hpp"


CC::CC(uint32_t graphSize){
    this->graphSize = graphSize;
    this->ccCounter = 0;
    this->updateIndexSize = 0;
    this->visited = (int*) malloc(sizeof(int)*graphSize);
    this->ccindex = (uint32_t*) malloc(sizeof(uint32_t)* this->graphSize);
    for(int i = 0; i < graphSize; i++){
        this->ccindex[i] = UINT32_T_MAX;
        this->visited[i] = -1;
    }
    
    this->updateIndex = NULL;
}
CC::~CC(){
    //delete this->updateIndex;
    free(this->ccindex);
    free(this->visited);
    free(this->updateIndex);
}

void CC::print(){
    //cout << "the graph size is " << this->graphSize << endl;
    for(int i = 0; i < this->graphSize; i++){
        cout << i << " -> " << this->ccindex[i] << endl;
    }
    if(this->updateIndex != NULL)
    for(int i = 0; i < this->ccCounter; i++){
        cout << i << " -> " << this->updateIndex[i] << endl;
    }
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

void CC::findCC(Index* indexExternal, Index* indexInternal, uint32_t nodeId, uint32_t ccId){
   
    uint32_t version = ccId;
    Queue* queue = new Queue();
    queue->pushBack(nodeId);
    
    while(!queue->isEmpty()){
        nodeId = queue->popFront();
        this->ccindex[nodeId] = ccId;
        //cout << "i popped " << nodeId << " with version " << version << endl;
        Queue* neighbors = indexExternal->getNeighborsOfNode(nodeId);
        Queue* neighbors2 = indexInternal->getNeighborsOfNode( nodeId);
        
       
        while(!neighbors->isEmpty()){
            uint32_t neighbor = neighbors->popFront();
            //cout << visited[neighbor] << endl;
            if(visited[neighbor] != version){
                queue->pushBack(neighbor);
                //cout << "i pushed e" << neighbor << endl;
                visited[neighbor] = version;
            }
        }
        
         while(!neighbors2->isEmpty()){
            uint32_t neighbor = neighbors2->popFront();
            if(visited[neighbor] != version){
                queue->pushBack(neighbor);
                //cout << "I pushed i" << neighbor << endl;
                visited[neighbor] = version;
            }
        }
    }
    
}

void CC::findCCAll(Index* indexInternal, Index* indexExternal){
    uint32_t ccCounter = 0;
    this->ccCounter = 0;
    for(int i = 0; i < this->graphSize; i++){
        
        if(indexExternal->isAllocated(i) && !inComponent(i)){
            
            findCC(indexExternal, indexInternal, i, ccCounter);
            this->ccCounter = ccCounter;
            ccCounter++;
        }
    }
    this->ccCounter = ccCounter;
    
}
int CC::insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdT, uint32_t version){
    while(nodeIdS > this->graphSize || nodeIdT > this->graphSize){
        uint32_t oldSize = this->graphSize;
        uint32_t newSize = this->graphSize * 2;
        this->ccindex = (uint32_t*) realloc(this->ccindex, newSize);
        for(int i = oldSize; i < newSize; i ++){
            this->ccindex[i] = UINT32_T_MAX;
        }
        this->graphSize = newSize;
    }
    
    if(inComponent(nodeIdS) && inComponent(nodeIdT)){
        uint32_t componentS = this->ccindex[nodeIdS];
        uint32_t componentT = this->ccindex[nodeIdT];
        
        if(this->updateIndex[componentS] == UINT32_T_MAX && this->updateIndex[componentT] == UINT32_T_MAX){
            this->updateIndex[componentS] = version;
            this->updateIndex[componentT] = version;
                  

        }else if(this->updateIndex[componentS] != UINT32_T_MAX && this->updateIndex[componentT] == UINT32_T_MAX){
            uint32_t toUpdate1 = this->updateIndex[componentS];

            for(int i = 0 ; i < ccCounter; i++){
                if(this->updateIndex[i] == toUpdate1){
                    this->updateIndex[i] = version;
                }
                
            }
            this->updateIndex[componentT] = version;
            
        }else if(this->updateIndex[componentS] == UINT32_T_MAX && this->updateIndex[componentT] != UINT32_T_MAX){
            uint32_t toUpdate1 = this->updateIndex[componentT];

            for(int i = 0 ; i < ccCounter; i++){
                if(this->updateIndex[i] == toUpdate1){
                    this->updateIndex[i] = version;
                }
                
            }
            this->updateIndex[componentS] = version;
        }else if(this->updateIndex[componentS] != UINT32_T_MAX && this->updateIndex[componentT] != UINT32_T_MAX){
            if(this->updateIndex[componentS] == this->updateIndex[componentT])
                return 0;
            uint32_t toUpdate1 = this->updateIndex[componentS];
            uint32_t toUpdate2 = this->updateIndex[componentT];
            for(int i = 0 ; i < ccCounter; i++){
                if(this->updateIndex[i] == toUpdate1 || this->updateIndex[i] == toUpdate2){
                    this->updateIndex[i] = version;
                }
                
            }

        }

        
                    return 1;

        
        
    }
    
}
uint32_t CC::getCcCounter(){
    return this->ccCounter;
}

bool CC::sameComponent(uint32_t nodeS, uint32_t nodeT){
    //cout << this->ccindex[nodeS] << " " << this->ccindex[nodeT] << endl;
    if(this->ccindex[nodeS] == this->ccindex[nodeT])
        return true;
    else{
        
        uint32_t compS = this->ccindex[nodeS];
        uint32_t compT = this->ccindex[nodeT];
        if(this->updateIndex[compS] == this->updateIndex[compT])
            return true;
        else return false;
    }
        
}

void CC::setUpdateIndex(){
    this->updateIndex = (uint32_t*) malloc(sizeof(uint32_t)*ccCounter);
    for(int i = 0 ; i < ccCounter; i++)
        this->updateIndex[i] = UINT32_T_MAX;
    this->updateIndexSize = this->ccCounter;
}