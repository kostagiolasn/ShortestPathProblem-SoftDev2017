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
        
        
};

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
            //this->buffer[i].initialize_neighbors(2);
            //this->buffer[i].initialize_edgeProperty(2);

            // the default offset is initialized at 0
            this->buffer[i].set_offset(0);
            this->buffer[i].set_neighborsSize(0);

            // then procceed to initialize the neighbors and edgeProperty arrays 
            // by setting them to UINT32_T_MAX, i.e. 2^32 - 1

            for(int j = 0; j < 2; j++) {
                this->buffer[i].insertNeighborAtPosition(UINT32_T_MAX, j);
            }
            
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
                //this->buffer[i].initialize_neighbors(2);
                //this->buffer[i].initialize_edgeProperty(2);

                // the default offset is initialized at 0
                this->buffer[i].set_offset(0);
                this->buffer[i].set_neighborsSize(0);

                // then procceed to initialize the neighbors and edgeProperty arrays 
                // by setting them to UINT32_T_MAX, i.e. 2^32 - 1

                for(int j = 0; j < 2; j++) {
                    this->buffer[i].insertNeighborAtPosition(UINT32_T_MAX, j);
                }
                
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

#endif	/* BUFFER_HPP */

