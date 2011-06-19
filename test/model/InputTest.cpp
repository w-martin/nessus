/*
 * File:   InputTest.cpp
 * Author: William Martin
 *
 * Created on Jun 13, 2011, 8:10:44 AM
 */

#include "InputTest.h"
#include "model/exceptions/EmptyInputException.h"
#include "model/exceptions/OutOfBoundsException.h"

CPPUNIT_TEST_SUITE_REGISTRATION(InputTest);

InputTest::InputTest() {
}

InputTest::~InputTest() {
}

void InputTest::setUp() {
    size = 5;
    input = new Input(size);
}

void InputTest::tearDown() {
    delete input;
}

void InputTest::testConstructor() {
    CPPUNIT_ASSERT_THROW(new Input(0), EmptyVectorException*);
}

void InputTest::testValue() {
    for (int i = 0; i < size; i++) {
        float value = 100.0f - i;
        input->setValue(i, value);
        CPPUNIT_ASSERT(input->getValue(i) == value);
    }
    CPPUNIT_ASSERT_THROW(input->setValue(size, size), OutOfBoundsException*);
}

void InputTest::testSize() {
    for (int i = 1; i <= size; i++) {
        Input *newInput = new Input(i);
        CPPUNIT_ASSERT(newInput->getSize() == i);
        delete newInput;
    }
}

