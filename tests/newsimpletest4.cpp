/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest4.cpp
 * Author: feta
 *
 * Created on November 5, 2016, 6:31 PM
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

void findShortestPath(uint32_t source, uint32_t target, Index indexInternal, Index indexExternal);

void testFindShortestPath() {
    uint32_t source;
    uint32_t target;
    Index indexInternal;
    Index indexExternal;
    findShortestPath(source, target, indexInternal, indexExternal);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testFindShortestPath (newsimpletest4) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest4" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest4)" << std::endl;
    testFindShortestPath();
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest4)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

