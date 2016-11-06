#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>
#include "nodeList.hpp"

 bool NodeList::neighborsFull() {
        return this->neighborsSize == 2;
    }
    
    bool NodeList::edgePropertyFull() {
        return this->edgePropertySize == 2;
    }
    
    void NodeList::set_offset(uint32_t offset) {
        this->offset = offset;
    }
        
    uint32_t NodeList::get_offset() {
        return offset;
    }
    
    size_t NodeList::get_neighborsSize() {
        return neighborsSize;
    }
    
    void NodeList::set_neighborsSize(uint32_t size) {
        this->neighborsSize = size;
    }
        
    void NodeList::increment_neighborsSize() {
        neighborsSize++;
    }
    
    OK_SUCCESS NodeList::insertNeighborAtPosition(uint32_t neighborId, int position) {
        neighbors[position] = neighborId;
        increment_neighborsSize();
        return 0;
    }
    
    OK_SUCCESS NodeList::insertEdgePropertyAtPosition(uint32_t neighborId, int position) {
            edgeProperty[position] = neighborId;
            return 0;
    }
    
    uint32_t NodeList::get_neighborAtIndex(int index) {
        return neighbors[index];
    }
    
    bool NodeList::containsNeighbor(uint32_t neighborId) {
        for(int i = 0; i < this->get_neighborsSize(); i++) {
            if(neighborId == this->get_neighborAtIndex(i)) {
                return true;
            }
        }
        
        return false;
    }
    
    uint32_t* NodeList::getNeighbors(){
        return this->neighbors;
    }

