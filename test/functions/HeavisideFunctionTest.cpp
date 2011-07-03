/* 
 * File:   HeavisideFunctionTest.cpp
 * Author: Will
 * 
 * Created on 29 June 2011, 23:20
 */

#include "nn-simulator/main/functions/HeavisideFunction.h"
#include "nn-simulator/main/model/Output.h"
#include "gtest/gtest.h"

namespace {

    class HeavisideFunctionTest : public ::testing::Test {
    protected:

        HeavisideFunctionTest() {
            heavisideFunction = new HeavisideFunction();
        }

        virtual ~HeavisideFunctionTest() {
            delete heavisideFunction;
        }
        HeavisideFunction *heavisideFunction;
    };

    /**
     * Tests whether the function method works correctly.
     * 
     */
    TEST_F(HeavisideFunctionTest, TestFunction) {
        EXPECT_EQ(0.0f, heavisideFunction->function(-1)->getValue());
        EXPECT_EQ(1.0f, heavisideFunction->function(1)->getValue());
    }
}
