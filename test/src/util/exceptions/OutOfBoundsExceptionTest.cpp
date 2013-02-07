/* 
 * File:   OutOfBoundsExceptionTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 9:58 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/util/exceptions/OutOfBoundsException.h"

#define message "test message"

namespace {

    class OutOfBoundsExceptionTest : public ::testing::Test {
    protected:

        OutOfBoundsExceptionTest() {
            testException = new OutOfBoundsException(message);
        }

        virtual ~OutOfBoundsExceptionTest() {
            delete testException;
        }
        OutOfBoundsException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(OutOfBoundsExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(OutOfBoundsExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new OutOfBoundsException();

        EXPECT_STREQ(OUT_OF_BOUNDS_MESSAGE, testException->what());
    }
}
