/* 
 * File:   UnsupportedConfigurationExceptionTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 9:57 AM
 */

#include "gtest/gtest.h"
#include "util/exceptions/UnsupportedConfigurationException.h"

#define message "test message"

namespace {

    class UnsupportedConfigurationExceptionTest : public ::testing::Test {
    protected:

        UnsupportedConfigurationExceptionTest() {
            testException = new UnsupportedConfigurationException(message);
        }

        virtual ~UnsupportedConfigurationExceptionTest() {
            delete testException;
        }
        UnsupportedConfigurationException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(UnsupportedConfigurationExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(UnsupportedConfigurationExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new UnsupportedConfigurationException();

        EXPECT_STREQ(UNSUPPORT_CONFIGURATION_MESSAGE, testException->what());
    }
}
