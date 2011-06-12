/*
 * File:   SigmoidFunctionTest.h
 * Author: William Martin
 *
 * Created on Jun 12, 2011, 5:23:44 PM
 */

#ifndef SIGMOIDFUNCTIONTEST_H
#define	SIGMOIDFUNCTIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "functions/SigmoidFunction.h"

class SigmoidFunctionTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(SigmoidFunctionTest);

    CPPUNIT_TEST(testFunction);
    CPPUNIT_TEST(testDerivative);

    CPPUNIT_TEST_SUITE_END();

public:
    SigmoidFunctionTest();
    virtual ~SigmoidFunctionTest();
    void setUp();
    void tearDown();

private:
    /**
     * Tests the function method.
     * 
     */
    void testFunction();
    /**
     * Tests the derivative method.
     * 
     */
    void testDerivative();
    SigmoidFunction *function;
    float testInput;
    float testFunctionOutput;
    float testDerivativeOutput;
};

#endif	/* SIGMOIDFUNCTIONTEST_H */

