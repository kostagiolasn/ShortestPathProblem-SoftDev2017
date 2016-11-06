#ifndef BUFFER_HPP
#define	BUFFER_HPP

#include "nodeList.hpp"

#define SIZE_BUFFER 2

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
        NodeList* allocNewNode();
        
        // No idea !!!
        NodeList* getListNode(uint32_t);
        
        // Destroys the buffer
        OK_SUCCESS destroyBuffer(Buffer*);
        
        // Doubles the Buffer
        OK_SUCCESS doubleBuffer();
        
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
        
        uint32_t get_firstListAvailable();
        
        // If the next available list number exceeds
        // the buffer's capacity, then the buffer is 
        // considered full, and its size must be doubled
        bool isFull();
        NodeList* getBuffer();
        
        void printBuffer();
        
        
};

#endif	/* BUFFER_HPP */

