#ifndef BFS_HPP
#define BFS_HPP

#define UINT32_T_MAX (0xffffffff)

#include <iostream>

#include "buffer.hpp"
#include "queue.hpp"
#include "index.hpp"


class BFS {
    
    private:
        int* inQueueInternal;
        
        int* inQueueExternal;
        
        Queue* queueInternal;
        Queue* queueExternal;
        
        
        size_t graphSize;
    
    public:
        
        BFS(size_t);
        ~BFS();
        
        int findShortestPath(Index*, Index*, Buffer*, Buffer*, uint32_t, uint32_t,  int);
        
};



#endif /* BFS_HPP */

