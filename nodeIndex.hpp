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

        // Returns the specific node's id
        uint32_t getNodeId();
        
        // It sets the node id
        OK_SUCCESS setNodeId(uint32_t);

        // Returns the list of neighbors for
        // a specific node
        NodeList* getListOfNeighbors();
        
        void setListOfNeighbors(NodeList* list) {
            listOfNeighbors = list;
        }
        
        // Checks if node exists in our index, i.e.
        // if its id is there instead of a UINT32_T_MAX
        bool nodeExists();
};
    NodeIndex::NodeIndex() {
        // We initialize the node id by using the max value for unsigned integers : 2^32 - 1
        nodeId = UINT32_T_MAX;
        listOfNeighbors = NULL;
    }
    
    NodeIndex::NodeIndex(uint32_t id) {
        nodeId = id;
    }

    uint32_t NodeIndex::getNodeId() {
        return nodeId;
    }
    
    OK_SUCCESS NodeIndex::setNodeId(uint32_t id) {
        nodeId = id;
        return OK_SUCCESS;
    }

    NodeList* NodeIndex::getListOfNeighbors() {
        return listOfNeighbors;
    }
    
    bool NodeIndex::nodeExists() {
        return (this->nodeId != UINT32_T_MAX);
    }

#endif	/* NODEINDEX_HPP */

