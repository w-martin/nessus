/*
 * File:   SigmoidFunctionTest.cpp
 * Author: William Martin
 *
 * Created on Jun 12, 2011, 5:23:44 PM
 */

#include "SigmoidFunctionTest.h"
#include "model/Output.h"
#include <math.h>


CPPUNIT_TEST_SUITE_REGISTRATION(SigmoidFunctionTest);

SigmoidFunctionTest::SigmoidFunctionTest() {
}

SigmoidFunctionTest::~SigmoidFunctionTest() {
}

void SigmoidFunctionTest::setUp() {
    testInput = 0.525f;
    testFunctionOutput = (1.0f / (1.0f + expf(-1.0f * testInput)));
    testDerivativeOutput = testFunctionOutput * (1.0f - testFunctionOutput);
    function = new SigmoidFunction();
}

void SigmoidFunctionTest::tearDown() {
    delete function;
}

void SigmoidFunctionTest::testFunction() {
    Output *result = function->function(testInput);
    CPPUNIT_ASSERT(result->getValue() == testFunctionOutput);
}

void SigmoidFunctionTest::testDerivative() {
    Output *result = function->derivative(testInput);
    CPPUNIT_ASSERT(result->getValue() == testDerivativeOutput);
}
