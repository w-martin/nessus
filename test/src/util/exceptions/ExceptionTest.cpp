/* 
 * File:   ExceptionTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 12:33 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/util/exceptions/Exception.h"

#define message "test message"

namespace {

    class ExceptionTest : public ::testing::Test {
    protected:

        ExceptionTest() {
            testException = new Exception(message);
        }

        virtual ~ExceptionTest() {
            delete testException;
        }
        Exception *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(ExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }
}
