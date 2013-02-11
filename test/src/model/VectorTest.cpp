/* 
 * File:   VectorTest.cpp
 * Author: will
 * 
 * Created on June 30, 2011, 7:58 AM
 */

#include <boost/test/unit_test.hpp>
#include "nn-simulator/main/model/Vector.h"
#include "nn-simulator/main/model/exceptions/EmptyVectorException.h"
#include "nn-simulator/main/util/exceptions/OutOfBoundsException.h"

struct VectorTest {

    VectorTest() {
        size = 2;
        vector = new Vector(size);
    }

    virtual ~VectorTest() {
        delete vector;
    }
    int size;
    Vector *vector;
};

BOOST_FIXTURE_TEST_SUITE(VectorTests, VectorTest)

/**
 * Tests whether an exception is thrown by the constructor.
 * 
 */
BOOST_AUTO_TEST_CASE(ConstructorExceptionTest) {
    BOOST_CHECK_THROW(new Vector(0), EmptyVectorException);
}

/**
 * Tests whether the <code>Vector</code> object is initialized
 * correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(InitializationTest) {
    BOOST_CHECK_EQUAL(size, vector->getSize());
    for (int i = 0; i < size; i++) {
        BOOST_CHECK_EQUAL(1.0f, vector->getValue(i));
    }
}

/*
 * Tests whether the getValue method throws an exception.
 * 
 */
BOOST_AUTO_TEST_CASE(GetValueExceptionTest) {
    BOOST_CHECK_THROW(vector->getValue(size + 1), OutOfBoundsException);
}

/*
 * Tests whether the setValue method throws an exception.
 * 
 */
BOOST_AUTO_TEST_CASE(SetValueExceptionTest) {
    BOOST_CHECK_THROW(vector->setValue(size + 1, 0.0f),
            OutOfBoundsException);
}

/*
 * Tests whether the value getter and setter work correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(ValueTest) {
    int max = 10;
    for (int i = 0; i < max; i++) {
        vector->setValue(0, i + 0.5f);
        BOOST_CHECK_EQUAL(i + 0.5f, vector->getValue(0));
    }
}

/*
 * Tests whether the getSize method works correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(GetSizeTest) {
    int max = 10;
    for (int i = 1; i < 10; i++) {
        Vector *tmp = new Vector(i);
        BOOST_CHECK_EQUAL(i, tmp->getSize());
        delete tmp;
    }
}

BOOST_AUTO_TEST_SUITE_END()
