#include <iostream>
#include <stdlib.h>
#include "Index.hpp"
#include "BufferNode.hpp"


Index::Index(bool supportsHashTable) {
	indexNodes = (IndexNode*) malloc(sizeof(IndexNode) * INDEX_SIZE);
	size = INDEX_SIZE;
	for (int i = 0; i < size; i++)
		indexNodes[i].initialize();
	buffer = new Buffer();
	this->supportsHashTable = supportsHashTable;
}

Index::~Index() {
	for (int i = 0; i < size; i++)
		indexNodes[i].freeMemory();
	free(indexNodes);
	delete buffer;
}

void Index::addEdge(uint32_t sourceId, uint32_t targetId) {

	int newSize = size;
	while (sourceId >= newSize)
		newSize <<= 1;
	if (size != newSize)
		increaseIndex(newSize);

	if (supportsHashTable) {
		if (indexNodes[sourceId].lookUp(targetId))
			return;
		else
			indexNodes[sourceId].insertId(targetId);
	}
	int posInBuffer = indexNodes[sourceId].getOffsetLast();
	if (posInBuffer == -1) {
		posInBuffer = buffer->fetchNewBufferNode();
		indexNodes[sourceId].setOffsetFirst(posInBuffer);
		indexNodes[sourceId].setOffsetLast(posInBuffer);
	}
	BufferNode* bufferNode = buffer->getBufferNodeByOffset(posInBuffer);
	if (bufferNode->getNextAvailable() == NEIGHBOUR_SIZE) {
        int newPosInBuffer = buffer->fetchNewBufferNode();
        bufferNode = buffer->getBufferNodeByOffset(posInBuffer);
        bufferNode->setNextOffset(newPosInBuffer);
        bufferNode = buffer->getBufferNodeByOffset(newPosInBuffer);
        indexNodes[sourceId].setOffsetLast(newPosInBuffer);
    }

	bufferNode->addNodeId(targetId);
}

void Index::increaseIndex(int newSize) {
	indexNodes = (IndexNode*) realloc(indexNodes, sizeof(IndexNode) * newSize);
	for (int i = size; i < newSize; i++)
		indexNodes[i].initialize();
	size = newSize;
}

Queue* Index::getNeighborsOfNode(uint32_t nodeId) {
	Queue* queue = new Queue();
	int posInBuffer = indexNodes[nodeId].getOffsetFirst();

	while (posInBuffer != -1) {
		BufferNode* bufferNode = buffer->getBufferNodeByOffset(posInBuffer);
		for (int i = 0; i < bufferNode->getNextAvailable(); i++)
			queue->pushBack(bufferNode->getNodeIdInArray(i));

		posInBuffer = bufferNode->getNextOffset();
	}

	return queue;
}

  uint32_t Index::getNeighborsOfLevel( Queue* queue, uint32_t level){
        QueueNode * temp = queue->getHead();
        uint32_t size = 0;
        while(temp != NULL && temp->level == level){
		Queue* neighbors = this->getNeighborsOfNode( temp->nodeId);
            size = size + neighbors->getSize();
		if(neighbors!=NULL)
			delete neighbors;
            temp = temp->next;
        }
        return size;
    }

		bool Index::isAllocated(uint32_t nodeId){
<<<<<<< HEAD
				if(this->indexNodes[nodeId].getOffsetFirst() != -1)
=======
				if(this->indexNodes[nodeId].getOffsetFirst() == -1)
>>>>>>> 779dac4661bc2ddf5ac78fd0dcc9a2646c710e32
					return false;
				else return true;
		}
