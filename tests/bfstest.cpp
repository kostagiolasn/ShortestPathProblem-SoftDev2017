/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bfstest.cpp
 * Author: feta
 *
 * Created on November 5, 2016, 3:05 PM
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "bfstest test 1" << std::endl;
}

void test2() {
    std::cout << "bfstest test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (bfstest) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% bfstest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (bfstest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (bfstest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (bfstest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (bfstest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

