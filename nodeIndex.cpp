#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>
#include "nodeIndex.hpp"
NodeIndex::NodeIndex() {
        // We initialize the node id by using the max value for unsigned integers : 2^32 - 1
        nodeId = UINT32_T_MAX;
        offsetNeighbors = -1;
        offsetNeighborsLast = -1;
    }
    NodeIndex::NodeIndex(uint32_t id) {
        nodeId = id;
    }

    uint32_t NodeIndex::getNodeId() {
        return nodeId;
    }
    
    OK_SUCCESS NodeIndex::setNodeId(uint32_t id) {
        nodeId = id;
        return 0;
    }
    
    bool NodeIndex::nodeExists() {
        return (this->nodeId != UINT32_T_MAX);
    }
    
    int NodeIndex::get_offsetNeighbors() {
        return this->offsetNeighbors;
    }
        
    void NodeIndex::set_offsetNeighbors(int offset) {
        this->offsetNeighbors = offset;
    }
    
    void NodeIndex::set_offsetNeighborsLast(int offset){
        this->offsetNeighborsLast = offset;
    }
    
    int NodeIndex::get_offsetNeighborsLast(){
        return this->offsetNeighborsLast;
    }
