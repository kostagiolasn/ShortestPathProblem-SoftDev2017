#ifndef NODEINDEX_HPP
#define	NODEINDEX_HPP

#include "nodeList.hpp"

class NodeIndex {
    private:
        int offsetNeighbors;
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
        
        int get_offsetNeighbors();
        
        void set_offsetNeighbors(int);
        
        // Checks if node exists in our index, i.e.
        // if its id is there instead of a UINT32_T_MAX
        bool nodeExists();
        
       
};
    
   
#endif	/* NODEINDEX_HPP */

