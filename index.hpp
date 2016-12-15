 #ifndef __INDEX_HPP__
#define __INDEX_HPP__

#define INDEX_SIZE 10000

#include <stdint.h>
#include "IndexNode.hpp"
#include "Buffer.hpp"
#include "queue.hpp"

class Index {
private:
	IndexNode* indexNodes;
	int size;
	Buffer* buffer;
	bool supportsHashTable;

	void increaseIndex(int);
public:
	Index(bool = 0);
	~Index();
	void addEdge(uint32_t, uint32_t);
	Queue* getNeighborsOfNode(uint32_t);
	uint32_t getNeighborsOfLevel(Queue*, uint32_t);
	bool isAllocated(uint32_t nodeId);
};


#endif
