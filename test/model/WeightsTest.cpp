/* 
 * File:   WeightsTest.cpp
 * Author: will
 * 
 * Created on June 19, 2011, 6:48 PM
 */

#include "WeightsTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(WeightsTest);

WeightsTest::WeightsTest() {
}

WeightsTest::~WeightsTest() {
}

void WeightsTest::setUp() {
    size = 100;
}

void WeightsTest::tearDown() {
}

void WeightsTest::testConstructor() {
    Weights *vector = new Weights(size);
    CPPUNIT_ASSERT(size == vector->getSize());
    delete vector;
}
