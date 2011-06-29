
#include "functions/HeavisideFunction.h"
#include "model/Output.h"
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
    TEST_F(HeavisideFunctionTest, FunctionTest) {
        EXPECT_EQ(0.0f, heavisideFunction->function(-1)->getValue());
        EXPECT_EQ(1.0f, heavisideFunction->function(1)->getValue());
    }
}

