#ifndef CC_HPP
#define CC_HPP

#define UINT32_T_MAX (0xffffffff)
#include <iostream>
#include "updateIndex.hpp"
#include "Index.hpp"
using namespace std;

class CC{
    private:
        uint32_t* ccindex;
        UpdateIndex* updateIndex;
        uint32_t metricVal;
        uint32_t graphSize;
        uint32_t ccCounter;
    public:
        CC(uint32_t);
        ~CC();
        void print();
        void insert(uint32_t, uint32_t);
        bool inComponent(uint32_t);
        void findCC(Index*, Index*, uint32_t, uint32_t);
        void findCCAll(Index* , Index* );
        int insertNewEdge(uint32_t, uint32_t, Index*);
        uint32_t getCcCounter();

};


#endif /* CC_HPP */
