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
#include "scc.hpp"
#include "Grails.h"

void printGraph(Index*, Buffer*);

void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);

int parseFileGraph(std::string stream, Index* externalIndex, Index* internalIndex);

void freeVariables(Index* indexExternal, Index* indexInternal);

void parseFileWorkLoad(std::string stream1, std::string stream, Index* indexInternal, Index* indexExternal, int);

void parseFileWorkLoadStatic(std::string stream, Index*, Index*, int, SCC*);

void createSccIndex(std::string, Index*, SCC*);


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
    int largestNodeId;
    try {

        largestNodeId = parseFileGraph(fileGraph, indexExternal, indexInternal);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 2;
    }

    //

    //std::cout << grailsIndex->isReachableGrailIndex(0, 1) << std::endl;
    //std::cout << grailsIndex->isReachableGrailIndex(5, 1) << std::endl;





    try {

       parseFileWorkLoad(fileGraph, fileWorkLoad, indexInternal, indexExternal, largestNodeId);//cc->print();


    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 3;
    }



    fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    freeVariables(indexExternal, indexInternal);


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


int parseFileGraph(std::string stream, Index* externalIndex, Index* internalIndex) {
    int largestNodeId = 0;
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
            if(idSource > largestNodeId)
                largestNodeId = idSource;
            if(idTarget > largestNodeId)
                largestNodeId = idTarget;
            //std::cout << idSource << " --> " << idTarget << std::endl;
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
    return largestNodeId;
}


void createSccIndex(std::string stream, Index* index, SCC* scc) {
    int largestNodeId = 0;
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

            idSource = scc->id_belongs_to_component[idSource];
            idTarget = scc->id_belongs_to_component[idTarget];

            if (! (idSource == idTarget)){
                index->addEdge(idSource, idTarget);
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

void parseFileWorkLoad(std::string fileGraph, std::string stream, Index* indexInternal, Index* indexExternal, int largestNodeId) {
    char queryType;
    bool dynamic = true;
    int posaUpdates = 0;
SCC* scc;
Index* indexSCC;
Grails* grailsIndex;
CC* cc;
    int grailsNo = 0;

    int idSource, idTarget, err = 0;
    ifstream file;
    std::string line;
    int version = 0;
    uint32_t ccVersion = 0;
    file.open(stream.c_str());

    BFS* bfs = new BFS(largestNodeId + 1);

    while(std::getline(file, line)) {
        std::istringstream iss(line);
        queryType = iss.peek();
        if(queryType == 'S'){
          dynamic = false;
          scc = new SCC(largestNodeId + 1);
          scc->Tarjan(largestNodeId + 1, indexExternal, indexInternal);

          indexSCC = new Index(true);

          try {

              createSccIndex(fileGraph, indexSCC, scc);
          } catch (std::string err) {
              std::cerr << err << std::endl;
          }

          grailsIndex = new Grails(indexSCC, scc->getCurrentComponentsCount());

          grailsIndex->buildIndex();
          continue;
        }
        if(queryType == 'D'){
          cc = new CC(largestNodeId + 1);



          cc->findCCAll(indexInternal, indexExternal);
          cc->setUpdateIndex();
          continue;
        }
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

              if(!dynamic){
                version++;

                   if (grailsIndex->isReachableGrailIndex(scc->id_belongs_to_component[idSource],
                                                          scc->id_belongs_to_component[idTarget])) {
                       cout << bfs->findShortestPath(indexInternal, indexExternal, idSource, idTarget, version) << endl;
                   } else {
                       cout << "-1" << endl;
                       posaUpdates++;
                       grailsNo++;
                   }
              }else{

                version++;
                if(cc->sameComponent(idSource, idTarget)){
                  cout << bfs->findShortestPath(indexInternal, indexExternal, idSource, idTarget, version) << endl;
                }else
                  cout << "-1" << endl;

              }
            }

            if(queryType == 'A'){

                indexInternal->addEdge(idTarget, idSource);
                indexExternal->addEdge(idSource, idTarget);
                cc->insertNewEdge(idSource, idTarget, ccVersion);
                ccVersion++;
            }

        }

    }



    file.close();

    if(err) {
        throw std::string("Work Load File input : unexpected format, a is : " + queryType);
    }
    delete bfs;


}

void parseFileWorkLoadStatic(std::string stream, Index* indexInternal, Index* indexExternal, int largestNode, SCC* scc) {
    char queryType;
    int idSource, idTarget, err = 0;
    ifstream file;
    std::string line;
    int version = 0;
    file.open(stream.c_str());

    BFS* bfs = new BFS(largestNode + 1);

    ofstream myfile;
    myfile.open("example.txt");

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


                version++;
                //std::cout << scc->estimateShortestPathStronglyConnectedComponents(indexInternal, indexExternal, idSource, idTarget, version) << std::endl;
                myfile << scc->estimateShortestPathStronglyConnectedComponents(indexInternal, indexExternal, idSource, idTarget, version);
                myfile << "\n";

            }
            if(queryType == 'A'){
                //indexInternal->addEdge(idTarget, idSource);
                //indexExternal->addEdge(idSource, idTarget);
                //cc->insertNewEdge(idSource, idTarget, ccVersion);
                //ccVersion++;
            }

        }

    }
    myfile.close();

    file.close();

    if(err) {
        throw std::string("Work Load File input : unexpected format, a is : " + queryType);
    }
    delete bfs;


}
