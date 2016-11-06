#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>
#include "index.hpp"

  Index::Index(bool ext) {

        initialSize = SIZE_INDEX;
        currentSize = 0;
        overflowSize = SIZE_INDEX;

        external = ext;
        this->index = (NodeIndex*) malloc(sizeof(NodeList) * overflowSize);
        for(int i = 0; i < overflowSize; i++) {
            this->index[i].setNodeId(UINT32_T_MAX);
            this->index[i].set_offsetNeighbors(0);
        }
    }
  
   Index::~Index() {
       free(this->index);
   }
    
    OK_SUCCESS Index::doubleIndex() {
        if( ( this->index = (NodeIndex*) realloc(this->index, sizeof(NodeIndex)*this->overflowSize*2) ) != NULL) {
            
            for(int i = this->overflowSize; i < this->overflowSize * 2; i++) {
                this->index[i].setNodeId(UINT32_T_MAX);
                this->index[i].set_offsetNeighbors(0);
                
            }
            
            this->overflowSize *= 2;
            
            return 0;
        }
        else
            return 1;
    }

    OK_SUCCESS Index::insertNode(uint32_t sourceNodeId, uint32_t targetNodeId, Buffer* buffer) {
        // all the magic happens here
        
        bool inside = true;
        // the first measure is to check whether the id
        // of the source node will produce an overflow
        // if we try to access its place on the index
        
        while(sourceNodeId >= this->get_overflowSize()) {
            
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
        
        if(index[sourceNodeId].nodeExists()) {
            
            //std::cout << "Node: " << sourceNodeId <<" Exists" << std::endl;
            //std::cout << "Node Exists" << std::endl;
            
            // if the source node exists in the index, 
            // just add the target node as its neighbor
            
            uint32_t temp_offset = buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->get_offset();
            //cout << "temp offset is " << temp_offset << endl;
            //cout << "neighbors are at offset: "<<temp_offset<<endl;
            // If neighbor already exists return.
             if(buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->containsNeighbor(targetNodeId)) {
                //std::cout << "Neighbor: " << targetNodeId << " exists" << std::endl;
                return 0;
            }
            
           if(temp_offset == 0) {
                inside = false;
           }
            
            if(inside) {
                //std::cout << "mphka inside "<<endl;
                // find the place in the buffer where the offset is 0 (i.e. where
                // the chain of lists for the node ends)
                while(buffer->getListNode(temp_offset)->get_offset() != 0) {

                    temp_offset = buffer->getListNode(temp_offset)->get_offset();
                    
                    // re-check if neighbor already exists
                    if(buffer->getListNode(temp_offset)->containsNeighbor(targetNodeId)) {
                        //std::cout << "Neighbor: " << targetNodeId << " exists" << std::endl;
                        //std::cout << "Neighbor exists" << std::endl;
                        return 0;
                    }
                }
                
                // A final check if neighbor exists
                if(buffer->getListNode(temp_offset)->containsNeighbor(targetNodeId)) {
                    //std::cout << "Neighbor: "<< targetNodeId << " exists" << std::endl;
                    //std::cout << "Neighbor exists" << std::endl;
                    return 0;
                }

                // if the aforementioned list has space for new neighbors
                if(!buffer->getListNode(temp_offset)->neighborsFull()) {

                    // go ahead and add the neighbor in the list
                    buffer->getListNode(temp_offset)->insertNeighborAtPosition( targetNodeId,
                            buffer->getListNode(temp_offset)->get_neighborsSize() );

                } else {
                    // if there isn't, that means that we have to add another list to the chain
                    // therefore, we must check first if the buffer is full
                    if(!buffer->isFull()) {

                        // if it isn't full, the list is already allocated, therefore just add
                        // the target node as a neighbor there
                        buffer->getListNode(temp_offset)->set_offset( buffer->get_firstListAvailable() );

                        buffer->getListNode(buffer->get_firstListAvailable())->insertNeighborAtPosition( targetNodeId,
                            buffer->getListNode(buffer->get_firstListAvailable())->get_neighborsSize() );
                    } else {

                        // if the buffer is full, we need to double it
                        if(buffer->doubleBuffer()) {
                            throw std::string("Doubling Buffer space : An error occurred");
                            return 1;
                        }

                        // and follow up with the same insertion
                        buffer->getListNode(temp_offset)->set_offset( buffer->get_firstListAvailable() );

                        buffer->getListNode(buffer->get_firstListAvailable())->insertNeighborAtPosition( targetNodeId,
                            buffer->getListNode(buffer->get_firstListAvailable())->get_neighborsSize() );
                    }

                    // lastly we need to increment the next available sentinel
                    buffer->incrementFirstAvailable();
                }
            }
            else {
                //if(!this->index[sourceNodeId].getListOfNeighbors()->neighborsFull()) {
                //   cout << temp_offset << endl; 
                if(!buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->neighborsFull()) {
                    //std::cout << "oi geitone dn einai gematoi " << this->index[sourceNodeId].get_offsetNeighbors() <<  std::endl;
                    // go ahead and add the neighbor in the list
                    buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->insertNeighborAtPosition( targetNodeId,
                            buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->get_neighborsSize() );
                    //std::cout << "geitones: " << buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->get_neighborsSize() << endl;
                    //buffer->printBuffer();
                    

                } else {
                    //std::cout << "oi geitones einai gematoi " << this->index[sourceNodeId].get_offsetNeighbors() <<  std::endl;
                    // if there isn't, that means that we have to add another list to the chain
                    // therefore, we must check first if the buffer is full
                    if(!buffer->isFull()) {

                        // if it isn't full, the list is already allocated, therefore just add
                        // the target node as a neighbor there
                        buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->set_offset( buffer->get_firstListAvailable() );

                        buffer->getListNode(buffer->get_firstListAvailable())->insertNeighborAtPosition( targetNodeId,
                        buffer->getListNode(buffer->get_firstListAvailable())->get_neighborsSize() );
                        //std::cout << "buffer offset: " << buffer->get_firstListAvailable() << endl;
                        //buffer->printBuffer();
                    } else {
                        //cout << "tha diaplasiasw" << endl;
                        // if the buffer is full, we need to double it
                        if(buffer->doubleBuffer()) {
                            throw std::string("Doubling Buffer space : An error occurred");
                            return 1;
                        }

                        // and follow up with the same insertion
                        buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->set_offset( buffer->get_firstListAvailable() );

                        buffer->getListNode(buffer->get_firstListAvailable())->insertNeighborAtPosition( targetNodeId,
                            buffer->getListNode(buffer->get_firstListAvailable())->get_neighborsSize() );
                        //std::cout << "1buffer offset: " << buffer->get_firstListAvailable() << endl;
                    }

                    // lastly we need to increment the next available sentinel
                    buffer->incrementFirstAvailable();
                }
            }
            
        } else {
            
            // if the source node doesn't exist,
            // add it to the index
            
            //std::cout << "Node: " << sourceNodeId << " is new" << std::endl;
            //std::cout << "Node is new" << std::endl;
            
            this->index[sourceNodeId].setNodeId(sourceNodeId);
            
            // check if there is space in the buffer for a list
            // to assign to the new node
            if(!buffer->isFull()) {
                //buffer->getListNode(this->index[sourceNodeId]->get_offsetNeighbors())
                //this->index[sourceNodeId].setListOfNeighbors(buffer->allocNewNode());
                this->index[sourceNodeId].set_offsetNeighbors(buffer->get_firstListAvailable());
            }
            else {
                // there is no space in the buffer, therefore we need to double
                // its size with realloc.
                if(buffer->doubleBuffer()) {
                    throw std::string("Doubling Buffer space : An error occurred");
                    return 1;
                }
                
                // Finally, we need to assign a new node to the new node
                this->index[sourceNodeId].set_offsetNeighbors(buffer->get_firstListAvailable());
            }
            
            // Insert the neighbor at the first position
             buffer->getListNode(this->index[sourceNodeId].get_offsetNeighbors())->insertNeighborAtPosition(targetNodeId, 0);
            //std::cout << "buffer offset: " << this->index[sourceNodeId].get_offsetNeighbors() << endl;
            // Either way, we need to increment the firstListAvailable
            buffer->incrementFirstAvailable();
        }
        
       // std::cout << "Node: " << sourceNodeId << " inserted successfully" << std::endl;
       //std::cout << "Node inserted successfully" << std::endl;
        
        return 0;
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
    
    void Index::print(Buffer* buffer) {
        
        for(int i = 0; i < this->get_overflowSize(); i++) {
            if(this->index[i].nodeExists()) {
                
                
                uint32_t temp_offset = buffer->getListNode(this->index[i].get_offsetNeighbors())->get_offset();
                
                std::cout << "Index number :" << i << std::endl;
                std::cout << "Printing neighbors :";
                for(int j = 0; j < buffer->getListNode(this->index[i].get_offsetNeighbors())->get_neighborsSize(); j++) {
                    std::cout << buffer->getListNode(this->index[i].get_offsetNeighbors())->get_neighborAtIndex(j) << std::endl;
                }
                std::cout << std::endl;
                
                
                while(temp_offset != 0) {

                    
                    for(int j = 0; j < buffer->getListNode(temp_offset)->get_neighborsSize(); j++) {
                        std::cout << buffer->getListNode(temp_offset)->get_neighborAtIndex(j)  << std::endl;
                    }
                    
                    temp_offset = buffer->getListNode(temp_offset)->get_offset();
                }
                
                /*if(buffer->getListNode(temp_offset)->get_neighborsSize() != 0) {
                    for(int j = 0; j < buffer->getListNode(temp_offset)->get_neighborsSize(); j++) {
                        std::cout << buffer->getListNode(temp_offset)->get_neighborAtIndex(j)  << std::endl;
                    }
                }*/
            }
        }
    }

    NodeIndex* Index::getNodeIndex(){
        return this->index;
    }
    
    Queue* Index::getNeighborsOfNode(Buffer* buffer, uint32_t nodeId){
        int j;
        Queue* neighbors = new Queue();
        
        uint32_t temp_offset = buffer->getListNode(this->index[nodeId].get_offsetNeighbors())->get_offset();
        //cout << "Offset is " << temp_offset << endl;
        for(int j = 0; j < buffer->getListNode(this->index[nodeId].get_offsetNeighbors())->get_neighborsSize(); j++) {
          
            neighbors->pushBack(buffer->getListNode(this->index[nodeId].get_offsetNeighbors())->get_neighborAtIndex(j));
        }
       
        //cout << "neighbor size is: " << buffer->getListNode(temp_offset)->get_neighborsSize()<<endl;
        while(buffer->getListNode(temp_offset)->get_offset() != 0) {

                    
            for(int j = 0; j < buffer->getListNode(temp_offset)->get_neighborsSize(); j++) {
                
                neighbors->pushBack(buffer->getListNode(temp_offset)->get_neighborAtIndex(j));
            }
                    
            temp_offset = buffer->getListNode(temp_offset)->get_offset();
        }
                
        if(buffer->getListNode(temp_offset)->get_neighborsSize() != 0) {
            for(int j = 0; j < buffer->getListNode(temp_offset)->get_neighborsSize(); j++) {
                
                neighbors->pushBack(buffer->getListNode(temp_offset)->get_neighborAtIndex(j));
            }
        }
        return neighbors;
    }
