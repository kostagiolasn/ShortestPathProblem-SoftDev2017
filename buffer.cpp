#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>
#include "buffer.hpp"

    Buffer::Buffer() {
        createBuffer();
    }
    
    Buffer::~Buffer() {
        free(this->buffer);
    }
    
    Buffer* Buffer::createBuffer() {

        initialSize = SIZE_BUFFER;
        currentSize = 0;
        overflowSize = SIZE_BUFFER;
      
        firstListAvailable = 0;
        
        this->buffer = (NodeList*) malloc(sizeof(NodeList) * overflowSize);
        
        for(int i = 0; i < overflowSize; i++) {

            // the default offset is initialized at 0
            this->buffer[i].set_offset(0);
            this->buffer[i].set_neighborsSize(0);
        }
        return this;
    }
    
    OK_SUCCESS Buffer::destroyBuffer( Buffer* buffer ) {
        delete buffer;
    }
    
    OK_SUCCESS Buffer::doubleBuffer() {
        if( ( this->buffer = (NodeList*) realloc(this->buffer, sizeof(NodeList)*this->overflowSize*2) ) != NULL) {
            
            for(int i = this->overflowSize; i < this->overflowSize * 2; i++) {

                // the default offset is initialized at 0
                this->buffer[i].set_offset(0);
                this->buffer[i].set_neighborsSize(0);
            }
            
            this->overflowSize *= 2;
            
            return 0;
        }
        else
            return 1;
    
    }
    
    NodeList* Buffer::getListNode(uint32_t index) {
        return &(this->buffer[index]);
    }
    
    NodeList* Buffer::allocNewNode() {
        return &(this->buffer[firstListAvailable]);
    }
            
    void Buffer::set_currentSize(size_t currentSize) {
        this->currentSize = currentSize;
    }

    size_t Buffer::get_currentSize() {
        return this->currentSize;
    }

    void Buffer::set_overflowSize(size_t overflowSize) {
        this->overflowSize = overflowSize;
    }

    size_t Buffer::get_overflowSize() {
        return this->overflowSize;
    }
    
    void Buffer::incrementFirstAvailable() {
        firstListAvailable += 1;
    }
    
    uint32_t Buffer::get_firstListAvailable() {
        return firstListAvailable;
    }
    
    bool Buffer::isFull() {
        return firstListAvailable == overflowSize;
    }

    NodeList* Buffer::getBuffer(){
        return this->buffer;
    }
    
    void Buffer::printBuffer(){
        int i, j;
        for(i = 0; i < this->get_overflowSize(); i++){
            for(j = 0; j < 2; j++){
                std::cout << this->buffer[i].get_neighborAtIndex(j) << " ";
               
            }
            std::cout << "offset of next: " << this->buffer[i].get_offset() << std::endl;
        }
    }