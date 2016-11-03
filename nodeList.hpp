#ifndef NODELIST_HPP
#define	NODELIST_HPP

#define UINT32_T_MAX (0xffffffff)

typedef int OK_SUCCESS;

class NodeList {
    
    private:
        uint32_t neighbors[2] = {UINT32_T_MAX, UINT32_T_MAX};
        uint32_t edgeProperty[2] = {UINT32_T_MAX, UINT32_T_MAX};
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
};
    
    bool NodeList::neighborsFull() {
        return this->neighborsSize == 2;
    }
    
    bool NodeList::edgePropertyFull() {
        return this->edgePropertySize == 2;
    }
    
    void NodeList::set_offset(uint32_t offset) {
        this->offset = offset;
    }
        
    uint32_t NodeList::get_offset() {
        return offset;
    }
    
    size_t NodeList::get_neighborsSize() {
        return neighborsSize;
    }
    
    void NodeList::set_neighborsSize(uint32_t size) {
        this->neighborsSize = size;
    }
        
    void NodeList::increment_neighborsSize() {
        neighborsSize++;
    }
    
    OK_SUCCESS NodeList::insertNeighborAtPosition(uint32_t neighborId, int position) {
        neighbors[position] = neighborId;
        increment_neighborsSize();
        return 0;
    }
    
    OK_SUCCESS NodeList::insertEdgePropertyAtPosition(uint32_t neighborId, int position) {
            edgeProperty[position] = neighborId;
            return 0;
    }
    
    uint32_t NodeList::get_neighborAtIndex(int index) {
        return neighbors[index];
    }

#endif	/* NODELIST_HPP */


