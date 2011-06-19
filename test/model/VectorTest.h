/* 
 * File:   VectorTest.h
 * Author: will
 *
 * Created on June 19, 2011, 6:42 PM
 */

#ifndef VECTORTEST_H
#define	VECTORTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "model/Vector.h"

class VectorTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(VectorTest);

    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testValue);
    CPPUNIT_TEST(testSize);

    CPPUNIT_TEST_SUITE_END();

public:
    VectorTest();
    virtual ~VectorTest();
    void setUp();
    void tearDown();
private:
    /**
     * Tests whether the constructor correctly throws an exception when
     * called with size = 0.
     * 
     */
    void testConstructor();
    /**
     * Tests whether the value getter and setter work correctly.
     * 
     */
    void testValue();
    /**
     * Tests whether the getSize method works correctly.
     * 
     */
    void testSize();
    Vector *vector;
    int size;
};

#endif	/* VECTORTEST_H */

