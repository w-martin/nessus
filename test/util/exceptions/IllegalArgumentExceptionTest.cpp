/* 
 * File:   IllegalArgumentExceptionTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 9:59 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/util/exceptions/IllegalArgumentException.h"

#define message "test message"

namespace {

    class IllegalArgumentExceptionTest : public ::testing::Test {
    protected:

        IllegalArgumentExceptionTest() {
            testException = new IllegalArgumentException(message);
        }

        virtual ~IllegalArgumentExceptionTest() {
            delete testException;
        }
        IllegalArgumentException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(IllegalArgumentExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(IllegalArgumentExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new IllegalArgumentException();

        EXPECT_STREQ(ILLEGAL_ARGUMENT_MESSAGE, testException->what());
    }
}
