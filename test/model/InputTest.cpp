/*
 * File:   InputTest.cpp
 * Author: William Martin
 *
 * Created on Jun 13, 2011, 8:10:44 AM
 */

#include "InputTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(InputTest);

InputTest::InputTest() {
}

InputTest::~InputTest() {
}

void InputTest::setUp() {
    size = 5;
}

void InputTest::tearDown() {
}

void InputTest::testConstructor() {
    Input *vector = new Input(size);
    CPPUNIT_ASSERT(size == vector->getSize());
    delete vector;
}

