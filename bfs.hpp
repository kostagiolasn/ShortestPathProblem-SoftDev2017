#ifndef BFS_HPP
#define BFS_HPP

#define UINT32_T_MAX (0xffffffff)

#include <iostream>

#include "buffer.hpp"
#include "queue.hpp"
#include "index.hpp"


class BFS {
    
    private:
        bool* visitedInternal;  
        bool* inQueueInternal;
        int* previousNodeInternal;
        
        bool* visitedExternal;
        bool* inQueueExternal;
        int* previousNodeExternal;
        
        Queue* queueInternal;
        Queue* queueExternal;
        
        size_t graphSize;
    
    public:
        
        BFS(size_t);
        ~BFS();
        
        int findShortestPath(Index*, Index*, Buffer*, Buffer*, uint32_t, uint32_t);
        
};



#endif /* BFS_HPP */

