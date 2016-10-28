#ifndef NODELIST_HPP
#define	NODELIST_HPP

#define UINT32_T_MAX 2^32-1

typedef int OK_SUCCESS;

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
        this->neighbors = new uint32_t[10];
        this->edgeProperty = new uint32_t[10];
        
        // the default offset is initialized at 0
        this->offset = 0;
        this->neighborsSize = 0;
        this->edgePropertySize = 0;
        
        // then procceed to initialize the neighbors and edgeProperty arrays 
        // by setting them to UINT32_T_MAX, i.e. 2^32 - 1
        
        for(i = 0; i < 10; i++) {
            this->neighbors[i] = UINT32_T_MAX;
            this->edgeProperty[i] = UINT32_T_MAX;
        }
    }
    
    NodeList::~NodeList() {
        delete neighbors;
        delete edgeProperty;
    }
    
    bool NodeList::neighborsFull() {
        return this->neighborsSize == 10;
    }
    
    bool NodeList::edgePropertyFull() {
        return this->edgePropertySize == 10;
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
            return 0;
    }

#endif	/* NODELIST_HPP */


