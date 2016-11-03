/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyTestSuit1.hpp
 * Author: feta
 *
 * Created on November 2, 2016, 6:48 PM
 */

#ifndef MYTESTSUIT1_HPP
#define MYTESTSUIT1_HPP


#include <cxxtest/TestSuite.h>

class MyTestSuite1 : public CxxTest::TestSuite{
public:
    void testAddition(void)
    {
        TS_ASSERT(1 + 1 > 1);
        TS_ASSERT_EQUALS(1 + 1,6);
    }
};

#endif /* MYTESTSUIT1_HPP */

