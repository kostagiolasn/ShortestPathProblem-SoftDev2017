/* 
 * File:   newsimpletest1.cpp
 * Author: nikos
 *
 * Created on Nov 7, 2016, 5:39:50 PM
 */

#include <stdlib.h>
#include <iostream>

#include "index.hpp"

/*
 * Simple C++ Test Suite
 */

void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);

void parseFileGraph(std::string stream, Index* externalIndex, Buffer* externalBuffer, Index* internalIndex, Buffer* internalBuffer);

void testStructureSizes(Index* externalIndex, Buffer* externalBuffer, Index* internalIndex, Buffer* internalBuffer) {
    if (externalIndex->get_overflowSize() == 16 && externalBuffer->get_overflowSize() == 16 && internalIndex->get_overflowSize() == 16 && internalBuffer->get_overflowSize() == 16) {
        std::cout << "%TEST_SUCCEEDED% time=0 testname=testStructureSizes (newsimpletest1)" << std::endl;
    } else {
        std::cout << "%TEST_FAILED% time=0 testname=testStructureSizes (newsimpletest1) message=unexpected structure sizes" << std::endl;
    }
}

void printGraph(Index*, Buffer*);

void testNeighborsOfNode(Queue* structExternalNeighbors, Queue* trueExternalNeighbors, Queue* structInternalNeighbors, Queue* trueInternalNeighbors) {
  
    bool successExternal = true;
    bool successInternal = true;
    
    uint32_t neighbor1;
    uint32_t neighbor2;
    
    while( !(structExternalNeighbors->isEmpty() && trueExternalNeighbors->isEmpty()) ) {
        neighbor1 = structExternalNeighbors->popFront();
        neighbor2 = trueExternalNeighbors->popFront();
        std::cout << "Neighbor 1:" << neighbor1 << endl;
        std::cout << "Neighbor 2:" << neighbor2 << endl;
        if(neighbor1 != neighbor2) {
            successExternal = false;
        }
    }
    while( !(structInternalNeighbors->isEmpty() && trueInternalNeighbors->isEmpty()) ) {
        neighbor1 = structInternalNeighbors->popFront();
        neighbor2 = trueInternalNeighbors->popFront();
        std::cout << "Neighbor 1:" << neighbor1 << endl;
        std::cout << "Neighbor 2:" << neighbor2 << endl;
        if(neighbor1 != neighbor2) {
            successExternal = false;
        }
    }
    
    
    if(successExternal && successInternal) {
        std::cout << "%TEST_SUCCEEDED% time=0 testname=testNeighborsOfNode (newsimpletest1)" << std::endl;
    }
    else {
        std::cout << "%TEST_FAILED% time=0 testname=testNeighborsOfNode (newsimpletest1) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    
    std::string fileGraph = "testGraph.txt";
    int state = 0;
    
    // Initialize the class objects here
    Index indexExternal = new Index(true);
    Buffer* bufferExternal = new Buffer();
    Index indexInternal = new Index(false);
    Buffer* bufferInternal = new Buffer();
    
    // Parse the file for the graph creation
    try {
        parseFileGraph(fileGraph, &indexExternal, bufferExternal, &indexInternal, bufferInternal);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 2;
    }
    
    std::cout << "%SUITE_STARTING% newsimpletest1" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testStructureSizes (newsimpletest1)" << std::endl;
    testStructureSizes(&indexExternal, bufferExternal, &indexInternal, bufferInternal);
    std::cout << "%TEST_FINISHED% time=0 testStructureSizes (newsimpletest1)" << std::endl;

    Queue* structNeighborsExternalOfOne = new Queue();
    Queue* structNeighborsInternalOfOne = new Queue();
    
    Queue* trueNeighborsExternalOfOne = new Queue();
    Queue* trueNeighborsInternalOfOne = new Queue();
    
    trueNeighborsExternalOfOne->pushFront(0);
    trueNeighborsExternalOfOne->pushFront(3);
    trueNeighborsExternalOfOne->pushFront(2);
    
    trueNeighborsInternalOfOne->pushFront(4);
    
    structNeighborsExternalOfOne = indexExternal.getNeighborsOfNode(bufferExternal, 1);
    //structNeighborsExternalOfOne->print();
    structNeighborsInternalOfOne = indexInternal.getNeighborsOfNode(bufferInternal, 1);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfOne, trueNeighborsExternalOfOne, structNeighborsInternalOfOne, trueNeighborsInternalOfOne);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfOne;
    delete structNeighborsInternalOfOne;
    delete trueNeighborsExternalOfOne;
    delete trueNeighborsInternalOfOne;
    
    
    Queue* structNeighborsExternalOfTwo = new Queue();
    Queue* structNeighborsInternalOfTwo = new Queue();
    
    Queue* trueNeighborsExternalOfTwo = new Queue();
    Queue* trueNeighborsInternalOfTwo = new Queue();
    
    trueNeighborsExternalOfTwo->pushFront(8);
    trueNeighborsInternalOfTwo->pushFront(7);
    trueNeighborsInternalOfTwo->pushFront(1);
    
    structNeighborsExternalOfTwo = indexExternal.getNeighborsOfNode(bufferExternal, 2);
    structNeighborsInternalOfTwo = indexInternal.getNeighborsOfNode(bufferInternal, 2);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfTwo, trueNeighborsExternalOfTwo, structNeighborsInternalOfTwo, trueNeighborsInternalOfTwo);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfTwo;
    delete structNeighborsInternalOfTwo;
    delete trueNeighborsExternalOfTwo;
    delete trueNeighborsInternalOfTwo;
    
    Queue* structNeighborsExternalOfThree = new Queue();
    Queue* structNeighborsInternalOfThree = new Queue();
    
    Queue* trueNeighborsExternalOfThree = new Queue();
    Queue* trueNeighborsInternalOfThree = new Queue();
    
    trueNeighborsExternalOfThree->pushFront(5);
    trueNeighborsExternalOfThree->pushFront(4);
    trueNeighborsInternalOfThree->pushFront(1);
    
    structNeighborsExternalOfThree = indexExternal.getNeighborsOfNode(bufferExternal, 3);
    structNeighborsInternalOfThree = indexInternal.getNeighborsOfNode(bufferInternal, 3);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfThree, trueNeighborsExternalOfThree, structNeighborsInternalOfThree, trueNeighborsInternalOfThree);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfThree ;
    delete structNeighborsInternalOfThree ;
    delete trueNeighborsExternalOfThree ;
    delete trueNeighborsInternalOfThree ;
    
    Queue* structNeighborsExternalOfFour = new Queue();
    Queue* structNeighborsInternalOfFour = new Queue();
    
    Queue* trueNeighborsExternalOfFour = new Queue();
    Queue* trueNeighborsInternalOfFour = new Queue();
    
    trueNeighborsExternalOfFour->pushFront(6);
    trueNeighborsExternalOfFour->pushFront(1);
    trueNeighborsInternalOfFour->pushFront(3);
    
    structNeighborsExternalOfFour = indexExternal.getNeighborsOfNode(bufferExternal, 4);
    structNeighborsInternalOfFour = indexInternal.getNeighborsOfNode(bufferInternal, 4);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfFour, trueNeighborsExternalOfFour, structNeighborsInternalOfFour, trueNeighborsInternalOfFour);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfFour;
    delete structNeighborsInternalOfFour;
    delete trueNeighborsExternalOfFour;
    delete trueNeighborsInternalOfFour;
    
    Queue* structNeighborsExternalOfFive = new Queue();
    Queue* structNeighborsInternalOfFive = new Queue();
    
    Queue* trueNeighborsExternalOfFive = new Queue();
    Queue* trueNeighborsInternalOfFive = new Queue();
    
    trueNeighborsExternalOfFive->pushFront(7);
    trueNeighborsInternalOfFive->pushFront(10);
    trueNeighborsInternalOfFive->pushFront(3);
    
    structNeighborsExternalOfFive = indexExternal.getNeighborsOfNode(bufferExternal, 5);
    structNeighborsInternalOfFive = indexInternal.getNeighborsOfNode(bufferInternal, 5);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfFive, trueNeighborsExternalOfFive, structNeighborsInternalOfFive, trueNeighborsInternalOfFive);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfFive;
    delete structNeighborsInternalOfFive ;
    delete trueNeighborsExternalOfFive ;
    delete trueNeighborsInternalOfFive ;
    
    Queue* structNeighborsExternalOfSix = new Queue();
    Queue* structNeighborsInternalOfSix = new Queue();
    
    Queue* trueNeighborsExternalOfSix = new Queue();
    Queue* trueNeighborsInternalOfSix = new Queue();
    
    trueNeighborsExternalOfSix->pushFront(7);
    trueNeighborsInternalOfSix->pushFront(10);
    trueNeighborsInternalOfSix->pushFront(4);
    
    structNeighborsExternalOfSix = indexExternal.getNeighborsOfNode(bufferExternal, 6);
    structNeighborsInternalOfSix = indexInternal.getNeighborsOfNode(bufferInternal, 6);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfSix, trueNeighborsExternalOfSix, structNeighborsInternalOfSix, trueNeighborsInternalOfSix);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfSix;
    delete structNeighborsInternalOfSix;
    delete trueNeighborsExternalOfSix;
    delete trueNeighborsInternalOfSix;
    
    Queue* structNeighborsExternalOfSeven = new Queue();
    Queue* structNeighborsInternalOfSeven = new Queue();
    
    Queue* trueNeighborsExternalOfSeven = new Queue();
    Queue* trueNeighborsInternalOfSeven = new Queue();
    
    trueNeighborsExternalOfSeven->pushFront(2);
    
    trueNeighborsInternalOfSeven->pushFront(6);
    trueNeighborsInternalOfSeven->pushFront(5);
    trueNeighborsInternalOfSeven->pushFront(9);
    
    structNeighborsExternalOfSeven = indexExternal.getNeighborsOfNode(bufferExternal, 7);
    structNeighborsInternalOfSeven = indexInternal.getNeighborsOfNode(bufferInternal, 7);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfSeven, trueNeighborsExternalOfSeven, structNeighborsInternalOfSeven, trueNeighborsInternalOfSeven);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfSeven ;
    delete structNeighborsInternalOfSeven ;
    delete trueNeighborsExternalOfSeven;
    delete trueNeighborsInternalOfSeven;
    
    Queue* structNeighborsExternalOfEight = new Queue();
    Queue* structNeighborsInternalOfEight = new Queue();
    
    Queue* trueNeighborsExternalOfEight = new Queue();
    Queue* trueNeighborsInternalOfEight = new Queue();
    
    trueNeighborsExternalOfEight->pushFront(9);
    trueNeighborsInternalOfEight->pushFront(2);
    
    structNeighborsExternalOfEight = indexExternal.getNeighborsOfNode(bufferExternal, 8);
    structNeighborsInternalOfEight = indexInternal.getNeighborsOfNode(bufferInternal, 8);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfEight, trueNeighborsExternalOfEight, structNeighborsInternalOfEight, trueNeighborsInternalOfEight);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfEight;
    delete structNeighborsInternalOfEight ;
    delete trueNeighborsExternalOfEight ;
    delete trueNeighborsInternalOfEight ;
    
    Queue* structNeighborsExternalOfNine = new Queue();
    Queue* structNeighborsInternalOfNine = new Queue();
    
    Queue* trueNeighborsExternalOfNine = new Queue();
    Queue* trueNeighborsInternalOfNine = new Queue();
    
    trueNeighborsExternalOfNine->pushFront(10);
    trueNeighborsExternalOfNine->pushFront(7);
    
    trueNeighborsInternalOfNine->pushFront(8);
    
    structNeighborsExternalOfNine = indexExternal.getNeighborsOfNode(bufferExternal, 9);
    structNeighborsInternalOfNine = indexInternal.getNeighborsOfNode(bufferInternal, 9);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfNine, trueNeighborsExternalOfNine, structNeighborsInternalOfNine, trueNeighborsInternalOfNine);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfNine;
    delete structNeighborsInternalOfNine;
    delete trueNeighborsExternalOfNine;
    delete trueNeighborsInternalOfNine;
    
    Queue* structNeighborsExternalOfTen = new Queue();
    Queue* structNeighborsInternalOfTen = new Queue();
    
    Queue* trueNeighborsExternalOfTen = new Queue();
    Queue* trueNeighborsInternalOfTen = new Queue();
    
    trueNeighborsExternalOfTen->pushFront(5);
    trueNeighborsExternalOfTen->pushFront(6);
    
    trueNeighborsInternalOfTen->pushFront(9);
    
    structNeighborsExternalOfTen = indexExternal.getNeighborsOfNode(bufferExternal, 10);
    structNeighborsInternalOfTen = indexInternal.getNeighborsOfNode(bufferInternal, 10);
    std::cout << "%TEST_STARTED% testNeighborsOfNode (newsimpletest1)" << std::endl;
    testNeighborsOfNode(structNeighborsExternalOfTen, trueNeighborsExternalOfTen, structNeighborsInternalOfTen, trueNeighborsInternalOfTen);
    std::cout << "%TEST_FINISHED% time=0 testNeighborsOfNode (newsimpletest1)" << std::endl;
    
    delete structNeighborsExternalOfTen;
    delete structNeighborsInternalOfTen;
    delete trueNeighborsExternalOfTen;
    delete trueNeighborsInternalOfTen;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

