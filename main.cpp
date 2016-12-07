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

#include "Index.hpp"
#include "bfs.hpp"
#include "cc.hpp"

void printGraph(Index*, Buffer*);

void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);

void parseFileGraph(std::string stream, Index* externalIndex, Index* internalIndex);

void freeVariables(Index* indexExternal, Index* indexInternal);

void parseFileWorkLoad(std::string stream, Index* indexInternal, Index* indexExternal);


using namespace std;


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
	Index* indexInternal = new Index();

    // Parse the file for the graph creation
    try {

        parseFileGraph(fileGraph, indexExternal, indexInternal);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 2;
    }
//	for (int i = 0; i <= 19; i++) {
//		Queue* queue = indexExternal->getNeighborsOfNode(i);
//		queue->print();
//	}

//    fprintf(stderr, "Time taken for insert: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//	return 0;
    //CC* cc = new CC(700000);



    //cout << indexExternal->getLargestNodeId() <<endl;
    //cc->findCCAll(indexInternal, indexExternal);
    //cout << cc->getCcCounter() << endl;
    //cc->print();
    try {

       parseFileWorkLoad(fileWorkLoad, indexInternal, indexExternal);//cc->print();

    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 3;
    }

    //indexExternal->print(bufferExternal);
   fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    freeVariables(indexExternal, indexInternal);
//delete cc;


    return state;
}

void printGraph(Index* indexExternal, Buffer* bufferExternal) {
//    indexExternal->print(bufferExternal);
}

void freeVariables(Index* indexExternal, Index* indexInternal) {
    delete indexExternal;

    delete indexInternal;

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


void parseFileGraph(std::string stream, Index* externalIndex, Index* internalIndex) {
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

            externalIndex->addEdge(idSource, idTarget);





            internalIndex->addEdge(idTarget, idSource);

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

void parseFileWorkLoad(std::string stream, Index* indexInternal, Index* indexExternal) {
    char queryType;
    int idSource, idTarget, err = 0;
    ifstream file;
    std::string line;
    int version = 0;
    file.open(stream.c_str());

    BFS* bfs = new BFS(2700000);

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
//                cout << version << endl;
//                version++;
//                cout << bfs->findShortestPath(indexInternal, indexExternal, idSource, idTarget, version) << endl;
                version++;
            //  if (version > 54184){
              //      cout << idSource << " " << idTarget << endl;
                    cout << bfs->findShortestPath(indexInternal, indexExternal, idSource, idTarget, version) << endl;
                //}
//                 bfs->findShortestPath(indexInternal, indexExternal, idSource, idTarget, version);

            }
            if(queryType == 'A'){
                indexInternal->addEdge(idTarget, idSource);
                indexExternal->addEdge(idSource, idTarget);
                //cc->insertNewEdge(idSource, idTarget, indexExternal);
            }

        }
    }

    file.close();

    if(err) {
        throw std::string("Work Load File input : unexpected format, a is : " + queryType);
    }
    delete bfs;


}
