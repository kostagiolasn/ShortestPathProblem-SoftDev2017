#ifndef NODELIST_HPP
#define	NODELIST_HPP

class NodeList {
    
    private:
        uint32_t* neighbors;
        uint32_t* edgeProperty;
        NodeList* nextListNode;
        
    public:
        //Constructor
        NodeList();
        
        //Destructor
        ~NodeList();
};

    NodeList::NodeList() {
        this->neighbors = new uint32_t*[INITIAL_NEIGHBOR_ARRAY_SIZE];
        this->edgeProperty = new uint32_t*[INITIAL_NEIGHBOR_ARRAY_SIZE];
    }

#endif	/* NODELIST_HPP */

