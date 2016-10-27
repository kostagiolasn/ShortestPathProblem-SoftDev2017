#ifndef INDEX_HPP
#define	INDEX_HPP

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include "nodeIndex.hpp"
#include "nodeList.hpp"
#include "buffer.hpp"

typedef int OK_SUCCESS;

const size_t INITIAL_INDEX_SIZE = 512;
const size_t INITIAL_BUFFER_SIZE = 512;
const size_t INITIAL_NEIGHBOR_ARRAY_SIZE = 10;

class Index {
    private:
        NodeIndex *index;
        size_t initialSize;     // the initial size of the index, default : 512
        size_t currentSize;     // the index's current size
        size_t overflowSize;    // the index's overflow size. If currentSize + 1 > overflowSize => double the table
        bool external;
        
    public:
        // Constructor
        Index();
        
        // Destructor
        ~Index();
        
        // Index Generator
        NodeIndex* createNodeIndex();
        
        // Node Insertion
        OK_SUCCESS insertNode( NodeIndex*, uint32_t sourceNodeId, uint32_t targetNodeId);
        
        // Get Node's List Head
        NodeList* getListHead( NodeIndex*, uint32_t nodeId);
        
        // Index Destructor
        OK_SUCCESS destroyNodeIndex( NodeIndex* );
        
        // Alters the current size of the index
        void set_currentSize(size_t);
        
        // Returns the current size of the index
        size_t get_currentSize(); 
        
        // bla bla
        void set_overflowSize(size_t);
        
        // bla bla
        size_t get_overflowSize();
        
        // Checks if this index is external, i.e.
        // if the index keeps information about the
        // edge A -> B. If it is external, B must be
        // stored as a neighbor of A.
        bool isExternal();
        
};

    Index::Index(bool ext) {
        initialSize = INITIAL_INDEX_SIZE;
        currentSize = 0;
        overflowSize = INITIAL_INDEX_SIZE;
        external = ext;
        this->index = createNodeIndex();
    }

    NodeIndex* Index::createNodeIndex() {
        this->index = new NodeIndex*[INITIAL_INDEX_SIZE];
    }

    OK_SUCCESS Index::insertNode(uint32_t sourceNodeId, uint32_t targetNodeId, Buffer* buffer) {
        // all the magic happens here
        
        // the first measure is to check whether the id
        // of the source node will produce an overflow
        // if we try to access its place on the index
        
        if(sourceNodeId > this->get_overflowSize()) {
            
            // if the id exceeds the the overflow size
            // of the index, we meet a condition where
            // its size has to be doubled
            
        }
        
        // After this, we proceed normally with the rest 
        // of the insertion
        
        if(index[sourceNodeId]->nodeExists()) {
            
            // if the source node exists in the index, 
            // just add the target node as its neighbor
            
        } else {
            
            // if the source node doesn't exist,
            // add it to the index
            
        }
    }

    NodeList* Index::getListHead(NodeIndex* index, uint32_t nodeId) {
        return index[nodeId]->getListOfNeighbors();
    }

    OK_SUCCESS Index::destroyNodeIndex( NodeIndex* index ) {
        delete index;
    }

    Index::~Index() {
        destroyNodeIndex(index);
    }
    
    void Index::set_currentSize(size_t currentSize) {
        this->currentSize = currentSize;
    }

    size_t Index::get_currentSize() {
        return this->currentSize;
    }

    void Index::set_overflowSize(size_t overflowSize) {
        this->overflowSize = overflowSize;
    }

    size_t Index::get_overflowSize() {
        return this->overflowSize;
    }

    bool Index::isExternal () {
        return this->external;
    }

#endif	/* INDEX_HPP */
