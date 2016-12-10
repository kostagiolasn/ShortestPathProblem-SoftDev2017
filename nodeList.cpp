#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>
#include "nodeList.hpp"
#include "bfs.hpp"

    NodeList::NodeList(){
        this->neighborsSize = 0;
        this->offset = -1;
        depth = 0;
    }
    bool NodeList::neighborsFull() {
        return this->neighborsSize == SIZE_NEIGHBORS;
    }
    
    bool NodeList::edgePropertyFull() {
        return this->edgePropertySize == SIZE_NEIGHBORS;
    }
    
    void NodeList::set_offset(int offset) {
        this->offset = offset;
    }
        
    int NodeList::get_offset() {
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

    void NodeList::incrementDepth() {
        depth++;
    }
    
    OK_SUCCESS NodeList::insertNeighborAtPosition(uint32_t neighborId, int position) {
        neighbors[position] = neighborId;
        increment_neighborsSize();
        return 0;
    }

    void NodeList::resetNeighbors() {
        memset(neighbors, UINT32_MAX, sizeof(uint32_t)*SIZE_NEIGHBORS);
        neighborsSize = 0 ;
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

    OK_SUCCESS NodeList::setDepth(uint32_t depth){
        this->depth = depth;
        return 0;
    }

    uint32_t NodeList::getDepth(){
        return this->depth;
    }

    uint32_t* NodeList::getNeighbors(){
        return this->neighbors;
    }

