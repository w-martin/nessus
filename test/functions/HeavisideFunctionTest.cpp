/*
 * File:   HeavisideFunctionTest.cpp
 * Author: William Martin
 *
 * Created on Jun 12, 2011, 4:40:55 PM
 */

#include "HeavisideFunctionTest.h"

#include "model/Output.h"


CPPUNIT_TEST_SUITE_REGISTRATION(HeavisideFunctionTest);

HeavisideFunctionTest::HeavisideFunctionTest() {
}

HeavisideFunctionTest::~HeavisideFunctionTest() {
}

void HeavisideFunctionTest::setUp() {
    testNoActivation = -0.5f;
    testYesActivation = 0.5f;
    function = new HeavisideFunction();
}

void HeavisideFunctionTest::tearDown() {
    delete function;
}

void HeavisideFunctionTest::testFunction() {
    Output *result = function->function(testNoActivation);
    CPPUNIT_ASSERT(result->getValue() == 0.0f);

    result = function->function(testYesActivation);
    CPPUNIT_ASSERT(result->getValue() == 1.0f);
}

