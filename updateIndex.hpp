#ifndef UPDATEINDEX_HPP
#define UPDATEINDEX_HPP

struct UpdateIndexNode{
    uint32_t component1;
    uint32_t component2;
    UpdateIndexNode* next;
};

class UpdateIndex{
    private:
        UpdateIndexNode* head;
        UpdateIndexNode* tail;
        
    public:
        UpdateIndex();
        ~UpdateIndex();
        void insertNode(uint32_t, uint32_t);
        void print();

};


#endif /* UPDATEINDEX_HPP */

