/* 
 * File:   EmptyVectorExceptionTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 12:55 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/exceptions/EmptyVectorException.h"

#define message "test message"

namespace {

    class EmptyVectorExceptionTest : public ::testing::Test {
    protected:

        EmptyVectorExceptionTest() {
            testException = new EmptyVectorException(message);
        }

        virtual ~EmptyVectorExceptionTest() {
            delete testException;
        }
        EmptyVectorException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(EmptyVectorExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(EmptyVectorExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new EmptyVectorException();

        EXPECT_STREQ(EMPTY_VECTOR_MESSAGE, testException->what());
    }
}
