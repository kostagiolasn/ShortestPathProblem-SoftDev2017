/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: feta
 *
 * Created on November 4, 2016, 11:09 PM
 */

#include <stdlib.h>
#include <iostream>
#include "index.hpp"
#include "buffer.hpp"
/*
 * Simple C++ Test Suite
 */

void printGraph(Index*, Buffer*);

void testPrintGraph() {
    Index* p0;
    Buffer* p1;
    printGraph(p0, p1);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPrintGraph (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testPrintGraph (newsimpletest)" << std::endl;
    testPrintGraph();
    std::cout << "%TEST_FINISHED% time=0 testPrintGraph (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

