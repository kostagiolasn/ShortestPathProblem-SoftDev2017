#ifndef BUFFER_HPP
#define	BUFFER_HPP

#include "nodeList.hpp"

class Buffer {

    private:
        NodeList* buffer;
        size_t initialSize;     // the initial size of the buffer, default : 512
        size_t currentSize;     // the buffer's current size (it may be deleted after all, we have firstListAvailable now)
        size_t overflowSize;    // the buffer's overflow size. If currentSize + 1 > overflowSize => double the table
        uint32_t firstListAvailable; // the number of the first available list in the buffer
    
    public:
        // Constructor
        Buffer();

        // Destructor
        ~Buffer();
        
        // Creates the buffer
        Buffer* createBuffer();
        
        // Allocates a new Node in the Buffer ** I believe it means double the buffer **
        NodeList* allocNewNode(Buffer*);
        
        // No idea !!!
        NodeList* getListNode(NodeList*);
        
        // Destroys the buffer
        OK_SUCCESS destroyBuffer(Buffer*);
        
        // Alters the current size of the buffer
        void set_currentSize(size_t);
        
        // Returns the current size of the buffer
        size_t get_currentSize(); 
        
        // Alters the buffer's overflow size, i.e.
        // the value which, after being incremented
        // by one exceeds the buffer's capacity
        
        void set_overflowSize(size_t);
        
        // Returns the overflow size
        size_t get_overflowSize();
        
        // After we assign a buffer list to 
        // a node, we call this, in order to
        // specify the next available list
        void incrementFirstAvailable();
        
        // If the next available list number exceeds
        // the buffer's capacity, then the buffer is 
        // considered full, and its size must be doubled
        bool isFull();
};

    Buffer::Buffer() {
        this->buffer = createBuffer();
    }
    
    Buffer* Buffer::createBuffer() {
        initialSize = INITIAL_INDEX_SIZE;
        currentSize = 0;
        overflowSize = INITIAL_INDEX_SIZE;
        
        firstListAvailable = 0;
        
        this->buffer = new NodeList*[INITIAL_INDEX_SIZE];
    }
    
    OK_SUCCESS Buffer::destroyBuffer( Buffer* buffer ) {
        delete buffer;
    }
    
    NodeList* Buffer::allocNewNode(Buffer*);
        
    NodeList* Buffer::getListNode(NodeList*);

    Buffer::~Buffer() {
        destroyBuffer(buffer);
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
    
    bool Buffer::isFull() {
        return firstListAvailable == overflowSize;
    }

#endif	/* BUFFER_HPP */

