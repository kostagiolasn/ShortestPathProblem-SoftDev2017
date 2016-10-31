#ifndef NODELIST_HPP
#define	NODELIST_HPP

#define UINT32_T_MAX (0xffffffff)

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
        
        void initialize_neighbors(uint32_t);
        
        void initialize_edgeProperty(uint32_t);
        
        void set_offset(uint32_t);
        
        uint32_t get_offset();
        
        OK_SUCCESS insertNeighborAtPosition(uint32_t, int);
        OK_SUCCESS insertEdgePropertyAtPosition(uint32_t, int);
        
        void set_neighborsSize(uint32_t);
                
        size_t get_neighborsSize();
        
        void increment_neighborsSize();
};

    NodeList::NodeList() {
        int i;
        this->neighbors = new uint32_t[2];
        this->edgeProperty = new uint32_t[2];
        
        // the default offset is initialized at 0
        this->offset = 0;
        this->neighborsSize = 0;
        this->edgePropertySize = 0;
        
        // then procceed to initialize the neighbors and edgeProperty arrays 
        // by setting them to UINT32_T_MAX, i.e. 2^32 - 1
        
        for(i = 0; i < 2; i++) {
            this->neighbors[i] = UINT32_T_MAX;
            this->edgeProperty[i] = UINT32_T_MAX;
        }
    }
    
    NodeList::~NodeList() {
        delete neighbors;
        delete edgeProperty;
    }
    
    bool NodeList::neighborsFull() {
        return this->neighborsSize == 2;
    }
    
    bool NodeList::edgePropertyFull() {
        return this->edgePropertySize == 2;
    }
    
    void NodeList::initialize_neighbors(uint32_t size) {
            this->neighbors = (uint32_t*) malloc(sizeof(uint32_t)*size);
            
            //for(int i = 0; i < size; i++) {
            //    neighbors[i] = UINT32_T_MAX;
            //}
    }
        
    void NodeList::initialize_edgeProperty(uint32_t size) {
        this->edgeProperty = (uint32_t*) malloc(sizeof(uint32_t)*size);
        
        //for(int i = 0; i < size; i++) {
        //    edgeProperty[i] = UINT32_T_MAX;
        //}
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

#endif	/* NODELIST_HPP */


