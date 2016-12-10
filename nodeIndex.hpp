#ifndef NODEINDEX_HPP
#define	NODEINDEX_HPP

#include "nodeList.hpp"
#include "hashTable.hpp"

class NodeIndex {
    private:
        int offsetNeighbors;
        int offsetNeighborsLast;
        uint32_t nodeId;
        HashTable* hashtable;
//        uint32_t hashDepth;
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

        OK_SUCCESS setDepth(uint32_t);

        OK_SUCCESS setHashTableNull();
        
        int get_offsetNeighbors();
        
        void set_offsetNeighbors(int);
        
        int get_offsetNeighborsLast();
        
        void set_offsetNeighborsLast(int);
//
//        uint32_t get_bucket_depth();
//
//        OK_SUCCESS incrementDepth();


        HashTable* get_hashTable();

        HashTable* init_hashTable();
        
        // Checks if node exists in our index, i.e.
        // if its id is there instead of a UINT32_T_MAX
        bool nodeExists();
        
       
};
    
   
#endif	/* NODEINDEX_HPP */

