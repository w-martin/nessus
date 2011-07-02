/* 
 * File:   OutputTest.cpp
 * Author: will
 * 
 * Created on June 30, 2011, 9:14 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Output.h"

namespace {

    class OutputTest : public ::testing::Test {
    protected:

        OutputTest() {
            value = 0.75f;
            output = new Output(value);
        }

        virtual ~OutputTest() {
            delete output;
        }
        float value;
        Output *output;
    };

    /*
     * Tests whether the getValue method returns the correct
     * value.
     * 
     */
    TEST_F(OutputTest, GetValueTest) {
        ASSERT_EQ(value, output->getValue());
    }
}
