/* 
 * File:   main.cpp
 * Author: nikos
 *
 * Created on October 28, 2016, 6:34 AM
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdint.h>
#include <time.h>

#include "index.hpp"
#include "bfs.hpp"
#include "cc.hpp"

void printGraph(Index*, Buffer*);

void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);

void parseFileGraph(std::string stream, Index* externalIndex, Buffer* externalBuffer, Index* internalIndex, Buffer* internalBuffer);

void freeVariables(Index* indexExternal, Buffer* bufferExternal, Index* indexInternal, Buffer* bufferInternal);

void parseFileWorkLoad(std::string stream, Index* indexInternal, Index* indexExternal, Buffer*, Buffer*, CC*);

int findShortestPath(uint32_t source, uint32_t target, Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal);

using namespace std;

struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {   
        return k % 10;
    }
};
int main(int argc, char** argv) {

    clock_t tStart = clock();

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
    Index* indexExternal = new Index(true);
    Buffer* bufferExternal = new Buffer();
    Index* indexInternal = new Index(false);
    Buffer* bufferInternal = new Buffer();
    
    // Parse the file for the graph creation
    try {
        
        parseFileGraph(fileGraph, indexExternal, bufferExternal, indexInternal, bufferInternal);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 2;
    }
    
    CC* cc = new CC(400000);
    cout << indexExternal->get_overflowSize() <<endl;
    cc->findCCAll(indexInternal, indexExternal, bufferInternal, bufferExternal);
    try {
      
      // parseFileWorkLoad(fileWorkLoad, indexInternal, indexExternal, bufferInternal, bufferExternal, cc);
      // cc->print();

    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 3;
    }
   
    //indexExternal->print(bufferExternal);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    freeVariables(indexExternal, bufferExternal, indexInternal, bufferInternal);



    return state;
}

void printGraph(Index* indexExternal, Buffer* bufferExternal) {
    indexExternal->print(bufferExternal);
}

void freeVariables(Index* indexExternal, Buffer* bufferExternal, Index* indexInternal, Buffer* bufferInternal) {
    delete indexExternal;
    delete bufferExternal;
    delete indexInternal;
    delete bufferInternal;
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


void parseFileGraph(std::string stream, Index* externalIndex, Buffer* externalBuffer, Index* internalIndex, Buffer* internalBuffer) {
    std::string line;
    char a;
    int idSource, idTarget, err = 0;
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

            int ret = externalIndex->insertNode(idSource, idTarget, externalBuffer);
           
            if( ret ) {
                //std::cout << ret << std::endl;
                if (ret != 23){
                    err = 2;
                    break;
                }
                continue;
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

void parseFileWorkLoad(std::string stream, Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal, CC* cc) {
    char queryType;
    int idSource, idTarget, err = 0;
    ifstream file;
    std::string line;
    
    file.open(stream.c_str());

    while(std::getline(file, line)) {
        std::istringstream iss(line);
        
        queryType = iss.peek();
        if(queryType == 'F'){
            // Process queries here
        }else {
            if(isdigit(queryType)) {
                err = 1;
                break;
            } 
            else if(!(iss >> queryType >> idSource >> idTarget)) {
                err = 1;
                break;
            }
          
            
            if(queryType == 'Q'){
                cout << findShortestPath(idSource, idTarget, indexInternal, indexExternal,  bufferInternal, bufferExternal) << endl;
            }
            if(queryType == 'A'){
                indexInternal->insertNode(idTarget, idSource, bufferInternal);
                indexExternal->insertNode(idSource, idTarget, bufferExternal);
                cc->insertNewEdge(idSource, idTarget);
            }

        }
    }   
    
    file.close();
    
    if(err) {
        throw std::string("Work Load File input : unexpected format, a is : " + queryType);
    }

}

int findShortestPath(uint32_t source, uint32_t target, Index* indexInternal, Index* indexExternal, Buffer* bufferInternal, Buffer* bufferExternal){
   BFS* bfs = new BFS(indexInternal->get_overflowSize() + 1);
   int result = bfs->findShortestPath(indexInternal, indexExternal, bufferInternal, bufferExternal, source, target);
   delete bfs;
   return result;
}
