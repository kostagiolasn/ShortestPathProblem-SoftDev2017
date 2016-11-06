/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: feta
 *
 * Created on November 6, 2016, 3:45 PM
 */

#include <stdlib.h>
#include <iostream>
#include "bfs.hpp"
#include "index.hpp"
#include "buffer.hpp"
/*
 * Simple C++ Test Suite
 */
void printGraph(Index*, Buffer*);
void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);

void parseFileGraph(std::string stream, Index* externalIndex, Buffer* externalBuffer, Index* internalIndex, Buffer* internalBuffer);
int findShortestPath(uint32_t source, uint32_t target, Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal);

void testFindShortestPath(uint32_t source, uint32_t target, int expectedResult, Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal) {
    //cout << source << " " << target << endl;
    
    int result = findShortestPath(source, target, indexInternal, indexExternal, bufferInternal, bufferExternal);
    if (result != expectedResult) {
        std::cout << "%TEST_FAILED% time=0 testname=testFindShortestPath (newsimpletest) message= " << source << " -> " << target << " :" << result << std::endl;
    }else
       std::cout << "Passed: "<< source << " - > " << target << " :" << result  << std::endl;
}

int main(int argc, char** argv) {
    std::string fileGraph = "tinyGraph.txt";
    std::string fileWorkLoad;
    int state = 0;
    
   
   
    // Initialize the class objects here
    Index indexExternal = new Index(true);
    Buffer* bufferExternal = new Buffer();
    Index indexInternal = new Index(false);
    Buffer* bufferInternal = new Buffer();
    
    // Parse the file for the graph creation
    try {
        //parseFileGraph(externalIndex, internalIndex, fileGraph);
        parseFileGraph(fileGraph, &indexExternal, bufferExternal, &indexInternal, bufferInternal);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 2;
    }
    
    
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(19, 6, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(17, 16, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;

    
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(8, 16, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(10, 2, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(14, 17, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(8, 19, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(4, 2, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(14, 6, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(19, 12, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(0, 10, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(18, 4, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(8, 9, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(3, 10, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest)" << std::endl;
    testFindShortestPath(19, 12, 2, &indexInternal, &indexExternal, bufferInternal, bufferExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest)" << std::endl;
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

