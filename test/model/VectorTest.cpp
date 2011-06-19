/* 
 * File:   VectorTest.cpp
 * Author: will
 * 
 * Created on June 19, 2011, 6:42 PM
 */

#include "VectorTest.h"
#include "model/exceptions/EmptyVectorException.h"
#include "model/exceptions/OutOfBoundsException.h"

CPPUNIT_TEST_SUITE_REGISTRATION(VectorTest);

VectorTest::VectorTest() {
}

VectorTest::~VectorTest() {
}

void VectorTest::setUp() {
    size = 5;
    vector = new Vector(size);
}

void VectorTest::tearDown() {
    delete vector;
}

void VectorTest::testConstructor() {
    CPPUNIT_ASSERT_THROW(new Vector(0), EmptyVectorException*);
}

void VectorTest::testValue() {
    for (int i = 0; i < size; i++) {
        float value = 100.0f - i;
        vector->setValue(i, value);
        CPPUNIT_ASSERT(vector->getValue(i) == value);
    }
    CPPUNIT_ASSERT_THROW(vector->setValue(size, size), OutOfBoundsException*);
}

void VectorTest::testSize() {
    for (int i = 1; i <= size; i++) {
        Vector *newVector = new Vector(i);
        CPPUNIT_ASSERT(newVector->getSize() == i);
        delete newVector;
    }
}
