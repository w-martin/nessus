/*
 * File:   InputTest.h
 * Author: William Martin
 *
 * Created on Jun 13, 2011, 8:10:43 AM
 */

#ifndef INPUTTEST_H
#define	INPUTTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "model/Input.h"

class InputTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(InputTest);

    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testValue);
    CPPUNIT_TEST(testSize);

    CPPUNIT_TEST_SUITE_END();

public:
    InputTest();
    virtual ~InputTest();
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
    Input *input;
    int size;
};

#endif	/* INPUTTEST_H */

