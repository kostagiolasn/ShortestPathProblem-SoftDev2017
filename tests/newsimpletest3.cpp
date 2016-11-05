/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest3.cpp
 * Author: feta
 *
 * Created on November 5, 2016, 4:57 PM
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>



/*
 * Simple C++ Test Suite
 */
void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);
void findShortestPath(uint32_t source, uint32_t target, Index indexInternal, Index indexExternal);

void testFindShortestPath() {
    uint32_t source;
    uint32_t target;
    Index indexExternal = new Index(true);
    Buffer* bufferExternal = new Buffer();
    Index indexInternal = new Index(false);
    Buffer* bufferInternal = new Buffer();
    
    findShortestPath(source, target, indexInternal, indexExternal);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testFindShortestPath (newsimpletest3) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::string fileGraph;
    std::string fileWorkLoad;
    int state = 0;
    
    try {
        args_setup(argc, argv, fileGraph, fileWorkLoad);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 1;
    }
    std::cout << "%SUITE_STARTING% newsimpletest3" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest3)" << std::endl;
    testFindShortestPath();
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest3)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

