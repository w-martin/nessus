/* 
 * File:   InputTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 12:25 AM
 */

#include "gtest/gtest.h"
#include "model/Input.h"

namespace {

    class InputTest : public ::testing::Test {
    protected:

        InputTest() {
            size = 5;
            input = new Input(size);
        }

        virtual ~InputTest() {
            delete input;
        }
        int size;
        Input *input;
    };

    /*
     * Tests whether the <code>Input</code> class extends 
     * <code>Vector</code> correctly.
     * 
     */
    TEST_F(InputTest, ExtensionTest) {
        ASSERT_EQ(size, input->getSize());
    }

    /*
     * Tests whether an exception is thrown when the size is set to
     * zero.
     * 
     */
    TEST_F(InputTest, ExceptionTest) {
        ASSERT_THROW(new Input(0), EmptyVectorException*);
    }
}
