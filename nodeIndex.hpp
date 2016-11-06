#ifndef NODEINDEX_HPP
#define	NODEINDEX_HPP

#include "nodeList.hpp"

class NodeIndex {
    private:
        uint32_t offsetNeighbors;
        uint32_t nodeId;
    public:
        //Constructor
        NodeIndex();
        
        NodeIndex(uint32_t);
        
        //Destructor
        ~NodeIndex();

        // Returns the specific node's id
        uint32_t getNodeId();
        
        // It sets the node id
        OK_SUCCESS setNodeId(uint32_t);
        
        uint32_t get_offsetNeighbors();
        
        void set_offsetNeighbors(uint32_t);
        
        // Checks if node exists in our index, i.e.
        // if its id is there instead of a UINT32_T_MAX
        bool nodeExists();
        
       
};
    NodeIndex::NodeIndex() {
        // We initialize the node id by using the max value for unsigned integers : 2^32 - 1
        nodeId = UINT32_T_MAX;
        offsetNeighbors = 0;
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
    
    uint32_t NodeIndex::get_offsetNeighbors() {
        return this->offsetNeighbors;
    }
        
    void NodeIndex::set_offsetNeighbors(uint32_t offset) {
        this->offsetNeighbors = offset;
    }

   
#endif	/* NODEINDEX_HPP */

