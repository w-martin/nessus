/*
 * File:   HeavisideFunctionTest.h
 * Author: William Martin
 *
 * Created on Jun 12, 2011, 4:40:50 PM
 */

#ifndef HEAVISIDEFUNCTIONTEST_H
#define	HEAVISIDEFUNCTIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "include/functions/HeavisideFunction.h"

/**
 * Tests HeavisideFunction.
 * 
 */
class HeavisideFunctionTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(HeavisideFunctionTest);

    CPPUNIT_TEST(testFunction);

    CPPUNIT_TEST_SUITE_END();

public:
    HeavisideFunctionTest();
    virtual ~HeavisideFunctionTest();
    void setUp();
    void tearDown();

private:
    /**
     * Tests the <code>function</code> method.
     * 
     */
    void testFunction();
    float testNoActivation;
    float testYesActivation;
    HeavisideFunction *function;
};

#endif	/* HEAVISIDEFUNCTIONTEST_H */

