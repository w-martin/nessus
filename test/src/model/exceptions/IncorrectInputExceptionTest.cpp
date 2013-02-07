/* 
 * File:   IncorrectInputExceptionTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 1:01 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/exceptions/IncorrectInputException.h"

#define message "test message"

namespace {

    class IncorrectInputExceptionTest : public ::testing::Test {
    protected:

        IncorrectInputExceptionTest() {
            testException = new IncorrectInputException(message);
        }

        virtual ~IncorrectInputExceptionTest() {
            delete testException;
        }
        IncorrectInputException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(IncorrectInputExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(IncorrectInputExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new IncorrectInputException();

        EXPECT_STREQ(INCORRECT_INPUT_MESSAGE, testException->what());
    }
}
