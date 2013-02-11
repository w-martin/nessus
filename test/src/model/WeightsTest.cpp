/* 
 * File:   WeightsTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 12:16 AM
 */

#include <boost/test/unit_test.hpp>
#include "nn-simulator/main/model/Weights.h"

struct WeightsTest {

    WeightsTest() {
        size = 5;
        weights = new Weights(size);
    }

    virtual ~WeightsTest() {
        delete weights;
    }
    int size;
    Weights *weights;
};

BOOST_FIXTURE_TEST_SUITE(WeightsTests, WeightsTest)

/*
 * Tests whether the <code>Weights</code> class extends 
 * <code>Vector</code> correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(ExtensionTest) {
    BOOST_CHECK_EQUAL(size, weights->getSize());
}

/*
 * Tests whether an exception is thrown when the size is set to
 * zero.
 * 
 */
BOOST_AUTO_TEST_CASE(ExceptionTest) {
    BOOST_CHECK_THROW(new Weights(0), EmptyVectorException);
}

BOOST_AUTO_TEST_SUITE_END()
