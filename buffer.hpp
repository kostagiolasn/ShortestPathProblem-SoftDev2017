#ifndef BUFFER_HPP
#define	BUFFER_HPP

#include "nodeList.hpp"

class Buffer {

    private:
        NodeList* buffer;
        size_t initialSize;     // the initial size of the buffer, default : 512
        size_t currentSize;     // the buffer's current size
        size_t overflowSize;    // the buffer's overflow size. If currentSize + 1 > overflowSize => double the table
    
    public:
        // Constructor
        Buffer();

        // Destructor
        ~Buffer();
        
        Buffer* createBuffer();
        
        NodeList* allocNewNode(Buffer*);
        
        NodeList* getListNode(NodeList*);
        
        OK_SUCCESS destroyBuffer(Buffer*);
};

    Buffer::Buffer() {
        initialSize = INITIAL_INDEX_SIZE;
        currentSize = 0;
        overflowSize = INITIAL_INDEX_SIZE;
        this->buffer = createBuffer();
    }
    
    Buffer* Buffer::createBuffer() {
        this->buffer = new NodeList*[INITIAL_INDEX_SIZE];
    }
    
    OK_SUCCESS Buffer::destroyBuffer( NodeIndex* index ) {

    }
    
    NodeList* Buffer::allocNewNode(Buffer*);
        
    NodeList* Buffer::getListNode(NodeList*);

    Buffer::~Buffer() {
        destroyBuffer(buffer);
    }

#endif	/* BUFFER_HPP */

