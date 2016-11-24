
#include "bfs.hpp"
#include "updateIndex.hpp"

#include "updateIndex.hpp"

UpdateIndex::UpdateIndex(){
    this->head = NULL;
    this->tail = NULL;
}

UpdateIndex::~UpdateIndex(){
    //delete[] this->list;
}

void UpdateIndex::insertNode(uint32_t component1, uint32_t component2){
    UpdateIndexNode* newNode = new UpdateIndexNode();
    newNode->component1 = component1;
    newNode->component2 = component2;
    newNode->next = NULL;
    if(this->head == NULL){
        this->head = newNode;
        this->tail = newNode;
        
    }else{
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

void UpdateIndex::print(){
    UpdateIndexNode * temp = this->head;
    while(temp != NULL){
        cout << temp->component1 << " " << temp->component2 << endl;
        temp = temp->next;
    }
}