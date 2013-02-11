/* 
 * File:   OutputTest.cpp
 * Author: will
 * 
 * Created on June 30, 2011, 9:14 AM
 */

#include <boost/test/unit_test.hpp>
#include "nn-simulator/main/model/Output.h"

struct OutputTest {

    OutputTest() {
        value = 0.75f;
        output = new Output(value);
    }

    virtual ~OutputTest() {
        delete output;
    }
    float value;
    Output *output;
};

BOOST_FIXTURE_TEST_SUITE(OutputTests, OutputTest)

/*
 * Tests whether the getValue method returns the correct
 * value.
 * 
 */
BOOST_AUTO_TEST_CASE(GetValueTest) {
    BOOST_CHECK_EQUAL(value, output->getValue());
}

BOOST_AUTO_TEST_SUITE_END()
