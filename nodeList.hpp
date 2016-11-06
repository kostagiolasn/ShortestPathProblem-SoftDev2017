#ifndef NODELIST_HPP
#define	NODELIST_HPP

#define UINT32_T_MAX (0xffffffff)

#define SIZE_NEIGHBORS 2

typedef int OK_SUCCESS;

class NodeList {
    
    private:
        uint32_t neighbors[SIZE_NEIGHBORS] = {UINT32_T_MAX};
        uint32_t edgeProperty[SIZE_NEIGHBORS] = {UINT32_T_MAX};
        size_t neighborsSize;
        size_t edgePropertySize;
        uint32_t offset;
        
    public:
        
        // Constructor
        NodeList();
        
        // Destructor
        ~NodeList();
        
        // Checks if neighbors array is full
        bool neighborsFull();
        
        // Checks if edgeProperty array is full
        bool edgePropertyFull();
        
        void initialize_neighbors(uint32_t);
        
        void initialize_edgeProperty(uint32_t);
        
        void set_offset(uint32_t);
        
        uint32_t get_offset();
        
        OK_SUCCESS insertNeighborAtPosition(uint32_t, int);
        OK_SUCCESS insertEdgePropertyAtPosition(uint32_t, int);
        
        void set_neighborsSize(uint32_t);
                
        size_t get_neighborsSize();
        
        void increment_neighborsSize();
        
        uint32_t get_neighborAtIndex(int);
               
        bool containsNeighbor(uint32_t);
        
        uint32_t* getNeighbors();
};
    
   

#endif	/* NODELIST_HPP */


