/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shortestPathTest.cpp
 * Author: feta
 *
 * Created on November 5, 2016, 3:09 PM
 */


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>

#include "index.hpp"
#include "bfs.hpp"
/*
 * Simple C++ Test Suite
 */
void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);

void parseFileGraph(std::string stream, Index* externalIndex, Buffer* externalBuffer, Index* internalIndex, Buffer* internalBuffer);
int findShortestPath(uint32_t source, uint32_t target, Index indexInternal, Index indexExternal);

void testFindShortestPath(uint32_t source, uint32_t target, Index indexInternal, Index indexExternal) {
    
    
    int result = findShortestPath(source, target, indexInternal, indexExternal);
    if (result != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testFindShortestPath (shortestPathTest) message=error message sample" << std::endl;
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
   
    std::cout << "%SUITE_STARTING% shortestPathTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testFindShortestPath (shortestPathTest)" << std::endl;
    testFindShortestPath(1, 10, indexInternal, indexExternal);
    std::cout << "%TEST_FINISHED% time=0 testFindShortestPath (shortestPathTest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad) {
    /* Does main's dirty job */
    int i, err = 0;
    
    fileGraph = "";
    fileWorkLoad = "";
    
    for(i = 1; i < argc; i++) {
        if( ! strcmp(argv[i], "-fGraph")) {
            if( i > (argc - 2) ) {
                err = 1;
                break;
            }
            fileGraph = std::string(argv[i+1]);
            i++;
        } else if( ! strcmp(argv[i], "-fWorkLoad")) {
            if( i > (argc - 2) ) {
                err = 1;
                break;
            }
            fileWorkLoad = std::string(argv[i+1]);
            i++;
        } else {
            err = 1;
            break;
        }
    }
    if(err) {
        throw std::string("Usage: " + std::string(argv[0]) + " -fGraph <Graph File> -fWorkLoad <Work Load File>");
    }
}

//void parseFileGraph(Index externalIndex, Index internalIndex, std::string stream) {
void parseFileGraph(std::string stream, Index* externalIndex, Buffer* externalBuffer, Index* internalIndex, Buffer* internalBuffer) {
    std::string line;
    char a;
    int idSource, idTarget, err;
    ifstream file;

    file.open(stream.c_str());
    
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        
        a = iss.peek();
        if(a == 'S')
            break;
        else {
            if(!isdigit(a)) {
                err = 1;
                break;
            } 
            else if(!(iss >> idSource >> idTarget)) {
                err = 1;
                break;
            }
            cout << idSource << " " << idTarget << endl;
            // Here is where the insertion takes place
            // In the external index, idTarget must be added as a neighbor to idSource
            // while in the internal index, idSource must be added as a neighbor to idTarget
            if( externalIndex->insertNode(idSource, idTarget, externalBuffer) ) {
                err = 2;
                break;
            }
            if( internalIndex->insertNode(idTarget, idSource, internalBuffer) ) {
                err = 2;
                break;
            }
            
        }
    }   
    
    file.close();
    
    if(err == 1) {
        throw std::string("Graph File input : unexpected format, value for a is :" + a);
    }
    else if(err == 2) {
        throw std::string("Graph File insertion : an error occurred");
    }
}

int findShortestPath(uint32_t source, uint32_t target, Index indexInternal, Index indexExternal){
    BFS* bfs = new BFS(10);
    return bfs->findShortestPath(indexInternal, indexExternal, source, target);
}