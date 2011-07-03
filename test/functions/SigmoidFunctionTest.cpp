/* 
 * File:   SigmoidFunctionTest.cpp
 * Author: Will
 * 
 * Created on June 29, 2011, 11:38 PM
 */

#include "nn-simulator/main/functions/SigmoidFunction.h"
#include "nn-simulator/main/model/Output.h"
#include "gtest/gtest.h"

namespace {

    class SigmoidFunctionTest : public ::testing::Test {
    protected:

        SigmoidFunctionTest() {
            sigmoidFunction = new SigmoidFunction();
        }

        virtual ~SigmoidFunctionTest() {
            delete sigmoidFunction;
        }
        SigmoidFunction *sigmoidFunction;
    };

    /**
     * Tests whether the function method works correctly.
     * 
     */
    TEST_F(SigmoidFunctionTest, TestFunction) {
        float value;
        value = sigmoidFunction->function(0.0f)->getValue();
        EXPECT_LT(0.0f, value);
        EXPECT_GT(1.0f, value);
        value = sigmoidFunction->function(1.0f)->getValue();
        EXPECT_LT(0.0f, value);
        EXPECT_GT(1.0f, value);
    }

    /**
     * Tests whether the derivative method works correctly.
     * 
     */
    TEST_F(SigmoidFunctionTest, TestDerivative) {
        float value;
        value = sigmoidFunction->function(0.5f)->getValue();
        value = value * (1.0f - value);
        EXPECT_EQ(value, sigmoidFunction->derivative(0.5f)->getValue());
    }
}
