/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: feta
 *
 * Created on Nov 4, 2016, 11:08:23 PM
 */

#include "newtestclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void printGraph(Index*, Buffer*);

void newtestclass::testPrintGraph() {
    Index* p0;
    Buffer* p1;
    printGraph(p0, p1);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

