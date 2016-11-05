/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest1.cpp
 * Author: feta
 *
 * Created on November 5, 2016, 3:47 PM
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

void printGraph(Index*, Buffer*);

void testPrintGraph() {
    Index* p0;
    Buffer* p1;
    printGraph(p0, p1);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPrintGraph (newsimpletest1) message=error message sample" << std::endl;
    }
}

void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);

void testArgs_setup() {
    int argc;
    char** argv;
    std::string& fileGraph;
    std::string& fileWorkLoad;
    args_setup(argc, argv, fileGraph, fileWorkLoad);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testArgs_setup (newsimpletest1) message=error message sample" << std::endl;
    }
}

void parseFileGraph(std::string stream, Index* externalIndex, Buffer* externalBuffer, Index* internalIndex, Buffer* internalBuffer);

void testParseFileGraph() {
    std::string stream;
    Index* externalIndex;
    Buffer* externalBuffer;
    Index* internalIndex;
    Buffer* internalBuffer;
    parseFileGraph(stream, externalIndex, externalBuffer, internalIndex, internalBuffer);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseFileGraph (newsimpletest1) message=error message sample" << std::endl;
    }
}

void parseFileWorkLoad(std::string stream, Index indexInternal, Index indexExternal);

void testParseFileWorkLoad() {
    std::string stream;
    Index indexInternal;
    Index indexExternal;
    parseFileWorkLoad(stream, indexInternal, indexExternal);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseFileWorkLoad (newsimpletest1) message=error message sample" << std::endl;
    }
}

void findShortestPath(uint32_t source, uint32_t target, Index indexInternal, Index indexExternal);

void testFindShortestPath() {
    uint32_t source;
    uint32_t target;
    Index indexInternal;
    Index indexExternal;
    findShortestPath(source, target, indexInternal, indexExternal);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testFindShortestPath (newsimpletest1) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest1" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testPrintGraph (newsimpletest1)" << std::endl;
    testPrintGraph();
    std::cout << "%TEST_FINISHED% time=0 testPrintGraph (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testArgs_setup (newsimpletest1)" << std::endl;
    testArgs_setup();
    std::cout << "%TEST_FINISHED% time=0 testArgs_setup (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testParseFileGraph (newsimpletest1)" << std::endl;
    testParseFileGraph();
    std::cout << "%TEST_FINISHED% time=0 testParseFileGraph (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testParseFileWorkLoad (newsimpletest1)" << std::endl;
    testParseFileWorkLoad();
    std::cout << "%TEST_FINISHED% time=0 testParseFileWorkLoad (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testFindShortestPath (newsimpletest1)" << std::endl;
    testFindShortestPath();
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (newsimpletest1)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

