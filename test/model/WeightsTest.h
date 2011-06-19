/* 
 * File:   WeightsTest.h
 * Author: will
 *
 * Created on June 19, 2011, 6:48 PM
 */

#ifndef WEIGHTSTEST_H
#define	WEIGHTSTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "model/Weights.h"

class WeightsTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(WeightsTest);

    CPPUNIT_TEST(testConstructor);

    CPPUNIT_TEST_SUITE_END();

public:
    WeightsTest();
    virtual ~WeightsTest();
    void setUp();
    void tearDown();

private:
    /**
     * Tests whether the constructor initializes a <code>Vector</code>
     * correctly.
     * 
     */
    void testConstructor();
    int size;
};

#endif	/* WEIGHTSTEST_H */

