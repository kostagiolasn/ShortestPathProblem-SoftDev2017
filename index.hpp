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

    OK_SUCCESS Index::insertNode(NodeIndex*, uint32_t sourceNodeId, uint32_t targetNodeId) {

    }

    NodeList* Index::getListHead(NodeIndex*, uint32_t nodeId) {

    }

    OK_SUCCESS Index::destroyNodeIndex( NodeIndex* index ) {

    }

    Index::~Index() {
        destroyNodeIndex(index);
    }

#endif	/* INDEX_HPP */

