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
    
    Buffer* Buffer::createBuffer() {

        initialSize = 512;
        currentSize = 0;
        overflowSize = 512;

        
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
        
    //NodeList* Buffer::getListNode(NodeList*);

    Buffer::~Buffer() {
        destroyBuffer(this);
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