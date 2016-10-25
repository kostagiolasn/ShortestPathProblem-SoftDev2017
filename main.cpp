
#include <iostream>
#include <string>
#include <cstring>

　/* 
 * File:   main.cpp
 * Author: nikos
 *
 * Created on October 20, 2016, 10:09 PM
 */


#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>

//#include "index.hpp"

using namespace std;
　
/*
 * 
 */

void args_setup(int argc, char* argv[], std::string& fileGraph, std::string& fileWorkLoad);

//void parseFileGraph(Index externalIndex, Index internalIndex, std::string stream);

//void parseFileWorkLoad(Index externalIndex, Index internalIndex, std::string stream);

void parseFileGraph(std::string stream);
void parseFileWorkLoad(std::string stream);

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
    
    // Parse the file for the graph creation
    try {
        //parseFileGraph(externalIndex, internalIndex, fileGraph);
        parseFileGraph(fileGraph);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 2;
    }
    
    // Parse the file containing the queries
    try {
        //parseFileWorkLoad(externalIndex, internalIndex, fileWorkLoad);
        parseFileWorkLoad(fileWorkLoad);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        state = 3;
    }
    
    return state;
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
void parseFileGraph(std::string stream) {
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
        }
    }   
    
    file.close();
    
    if(err) {
        throw std::string("Graph File input : unexpected format, value for a is :" + a);
    }
}

void parseFileWorkLoad(std::string stream) {
//void parseFileWorkLoad(Index externalIndex, Index internalIndex, std::string stream) {
    char queryType;
    int idSource, idTarget, err;
    ifstream file;
    std::string line;
    
    file.open(stream.c_str());
    
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        
        queryType = iss.peek();
        if(queryType == 'F')
            // Process queries here
            cout << "F found here" << endl;
        else {
            if(isdigit(queryType)) {
                err = 1;
                break;
            } 
            else if(!(iss >> queryType >> idSource >> idTarget)) {
                err = 1;
                break;
            }
            cout << queryType << " " << idSource << " " << idTarget << endl;
            // Here is where the insertion takes place
        }
    }   
    
    file.close();
    
    if(err) {
        throw std::string("Work Load File input : unexpected format, a is : " + queryType);
    }

}

