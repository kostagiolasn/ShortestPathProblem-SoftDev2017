#ifndef INDEX_HPP
#define	INDEX_HPP

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "nodeIndex.hpp"
#include "buffer.hpp"

typedef int OK_SUCCESS;

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
        
        Index(bool);
        // Destructor
        ~Index();
        
        // Index Generator
        NodeIndex* createNodeIndex();
        
        // Node Insertion
        OK_SUCCESS insertNode(uint32_t, uint32_t, Buffer*);
        
        // Get Node's List Head
        NodeList* getListHead( NodeIndex*, uint32_t nodeId);
        
        // Index Destructor
        OK_SUCCESS destroyNodeIndex( NodeIndex* );
        
        // Doubles the Index
        OK_SUCCESS doubleIndex();
        
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
        initialSize = 512;
        currentSize = 0;
        overflowSize = 512;
        external = ext;
        this->index = createNodeIndex();
    }

    NodeIndex* Index::createNodeIndex() {
        this->index = new NodeIndex[512];
        return this->index;
    }
    
    OK_SUCCESS Index::doubleIndex() {
        if( realloc(this->index, this->overflowSize*2) != NULL) {
            
            this->overflowSize *= 2;
            
            return 0;
        }
        else
            return 1;
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
            
            if(this->doubleIndex()) {
                throw std::string("Doubling Index space : An error occurred");
                return 1;
            }
            
        }
        
        // After this, we proceed normally with the rest 
        // of the insertion
        
        if(index[sourceNodeId]->nodeExists()) {
            
            // if the source node exists in the index, 
            // just add the target node as its neighbor
            
            // check if there is space in the buffer for a list
            // to assign to the new node
            if(!buffer->isFull())
                // If there is space available, assign the first available list
                this->index[sourceNodeId].setListOfNeighbors(buffer->allocNewNode());
            else {
                // there is no space in the buffer, therefore we need to double
                // its size with realloc.
                
                if(buffer->doubleBuffer()) {
                    throw std::string("Doubling Buffer space : An error occurred");
                    return 1;
                }
                
                // Finally, we need to assign a new node to the new node
                this->index[sourceNodeId]->setListOfNeighbors(buffer->allocNewNode());
                
            }
            
            // Either way, we need to increment the firstListAvailable
            buffer->incrementFirstAvailable();   
            
            // Finally, we must add the neighbor in the list of our NodeIndex
            if(this->index[sourceNodeId]->getListOfNeighbors()->neighborsFull()) {
                // Neighbor array is full, we need to point to a new list
                
                // Check if offset is 0, therefore assign it directly and augment the neighbors' size
                if(this->index[sourceNodeId]->getListOfNeighbors()->get_offset() == 0) {
                    this->index[sourceNodeId]->getListOfNeighbors()->set_offset( buffer->get_firstListAvailable() );
                    
                    // Finally assign it and augment the neighbors' size
                    this->index[sourceNodeId]->getListOfNeighbors()->insertNeighborAtPosition(targetNodeId, 
                            this->index[sourceNodeId]->getListOfNeighbors()->get_neighborsSize());
                }
                else {
                    // If offset is not 0, then it means that we need to go as far as
                    // needed in order to get an offset of 0
                    
                    uint32_t temp_offset = this->index[sourceNodeId]->getListOfNeighbors()->get_offset();
                    
                    while(buffer[temp_offset]->getListNode()->get_offset() != 0) {
                        
                        temp_offset = buffer[temp_offset]->getListNode()->get_offset();
                    }
                    
                    buffer[temp_offset]->getListNode()->set_offset( buffer->get_firstListAvailable() );
                    
                    // Finally assign it and augment the neighbors' size
                    
                    buffer[temp_offset]->getListNode()->insertNeighborAtPosition(targetNodeId, 
                            0);
                }
            } else {
                // If neighbor array isn't full, assign it directly and augment the neighbors' size
                this->index[sourceNodeId]->getListOfNeighbors()->insertNeighborAtPosition( targetNodeId,
                        this->index[sourceNodeId]->getListOfNeighbors()->get_neighborsSize() );
            }
            
        } else {
            
            // if the source node doesn't exist,
            // add it to the index
            
            this->index[sourceNodeId]->setNodeId(sourceNodeId);
            
            // check if there is space in the buffer for a list
            // to assign to the new node
            if(!buffer->isFull())
                this->index[sourceNodeId]->setListOfNeighbors(buffer->allocNewNode());
            else {
                // there is no space in the buffer, therefore we need to double
                // its size with realloc.
                if(buffer->doubleBuffer()) {
                    throw std::string("Doubling Buffer space : An error occurred");
                    return 1;
                }
                
                // Finally, we need to assign a new node to the new node
                this->index[sourceNodeId]->setListOfNeighbors(buffer->allocNewNode());
                
            }
            
            // Insert the neighbor at the first position
            this->index[sourceNodeId]->getListOfNeighbors()->insertNeighborAtPosition(targetNodeId, 0);
            
            // Either way, we need to increment the firstListAvailable
            buffer->incrementFirstAvailable();
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


