/* 
 * File:   LayerNotSetExceptionTest.cpp
 * Author: will
 * 
 * Created on 8th July 2011, 11:24 PM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/exceptions/LayerNotSetException.h"

#define message "test message"

namespace {

    class LayerNotSetExceptionTest : public ::testing::Test {
    protected:

        LayerNotSetExceptionTest() {
            testException = new LayerNotSetException(message);
        }

        virtual ~LayerNotSetExceptionTest() {
            delete testException;
        }
        LayerNotSetException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(LayerNotSetExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(LayerNotSetExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new LayerNotSetException();

        EXPECT_STREQ(LAYER_NOT_SET_MESSAGE, testException->what());
    }
}
