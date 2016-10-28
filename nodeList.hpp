#ifndef NODELIST_HPP
#define	NODELIST_HPP

class NodeList {
    
    private:
        uint32_t* neighbors;
        uint32_t* edgeProperty;
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
        
        void set_offset(uint32_t);
        
        uint32_t get_offset();
        
        OK_SUCCESS insertNeighborAtPosition(uint32_t, int);
        
        size_t get_neighborsSize();
        
        void increment_neighborsSize();
};

    NodeList::NodeList() {
        int i;
        this->neighbors = new uint32_t*[INITIAL_NEIGHBOR_ARRAY_SIZE];
        this->edgeProperty = new uint32_t*[INITIAL_NEIGHBOR_ARRAY_SIZE];
        
        // the default offset is initialized at 0
        this->offset = 0;
        this->neighborsSize = 0;
        this->edgePropertySize = 0;
        
        // then procceed to initialize the neighbors and edgeProperty arrays 
        // by setting them to UINT32_T_MAX, i.e. 2^32 - 1
        
        for(i = 0; i < INITIAL_NEIGHBOR_ARRAY_SIZE; i++) {
            this->neighbors[i] = UINT32_T_MAX;
            this->edgeProperty[i] = UINT32_T_MAX;
        }
    }
    
    NodeList::~NodeList() {
        delete neighbors;
        delete edgeProperty;
    }
    
    bool NodeList::neighborsFull() {
        return this->neighborsSize == INITIAL_NEIGHBOR_ARRAY_SIZE;
    }
    
    bool NodeList::edgePropertyFull() {
        return this->edgePropertySize == INITIAL_NEIGHBOR_ARRAY_SIZE;
    }
    
    void NodeList::set_offset(uint32_t offset) {
        this->offset = offset;
    }
        
    uint32_t NodeList::get_offset() {
        return offset;
    }
    
    size_t NodeList::get_neighborsSize() {
        return neighborsSize;
    };
        
    void NodeList::increment_neighborsSize() {
        neighborsSize++;
    }
    
    OK_SUCCESS NodeList::insertNeighborAtPosition(uint32_t neighborId, int position) {
            neighbors[position] = neighborId;
            increment_neighborsSize();
            return OK_SUCCESS;
    }

#endif	/* NODELIST_HPP */

