#ifndef NODEINDEX_HPP
#define	NODEINDEX_HPP

#include "nodeList.hpp"

class NodeIndex {
    private:
        NodeList* listOfNeighbors;
        uint32_t nodeId;
    public:
        //Constructor
        NodeIndex();
        
        //Destructor
        ~NodeIndex();

        uint32_t getNodeId();
        
        OK_SUCCESS setNodeId(uint32_t);

        NodeList* getListOfNeighbors();
};
    NodeIndex::NodeIndex() {
        nodeId = NULL;
    }
    NodeIndex::NodeIndex(uint32_t id) {
        nodeId = id;
    }

    uint32_t NodeIndex::getNodeId() {
        return nodeId;
    }
    
    OK_SUCCESS NodeIndex::setNodeId(uint32_t id) {
        nodeId = id;
    }

    NodeList* NodeIndex::getListOfNeighbors() {
        return listOfNeighbors;
    }

#endif	/* NODEINDEX_HPP */

