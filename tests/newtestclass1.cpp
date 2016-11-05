/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass1.cpp
 * Author: feta
 *
 * Created on Nov 5, 2016, 6:41:26 PM
 */

#include "newtestclass1.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass1);

newtestclass1::newtestclass1() {
}

newtestclass1::~newtestclass1() {
}

void newtestclass1::setUp() {
}

void newtestclass1::tearDown() {
}

void findShortestPath(uint32_t source, uint32_t target, Index indexInternal, Index indexExternal);

void newtestclass1::testFindShortestPath() {
    uint32_t source;
    uint32_t target;
    Index indexInternal;
    Index indexExternal;
    findShortestPath(source, target, indexInternal, indexExternal);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

