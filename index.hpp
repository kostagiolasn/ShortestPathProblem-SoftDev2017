#ifndef INDEX_HPP
#define	INDEX_HPP



#include "nodeIndex.hpp"
#include "buffer.hpp"
#include "queue.hpp"

#define SIZE_INDEX 8

typedef int OK_SUCCESS;

class Index {
    private:
        NodeIndex *index;
        size_t initialSize;     // the initial size of the index, default : 512
        size_t currentSize;     // the index's current size
        size_t overflowSize;    // the index's overflow size. If currentSize + 1 > overflowSize => double the table
        uint32_t largestNodeId;
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
        
        NodeIndex* getNodeIndex();
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

        OK_SUCCESS incrementCurrentSize();
        
        // bla bla
        size_t get_overflowSize();
        
        uint32_t getLargestNodeId();
        // Checks if this index is external, i.e.
        // if the index keeps information about the
        // edge A -> B. If it is external, B must be
        // stored as a neighbor of A.
        bool isExternal();
        
        void print(Buffer*);
        Queue* getNeighborsOfNode(Buffer* buffer, uint32_t nodeId);
        
        
};

  
#endif	/* INDEX_HPP */


