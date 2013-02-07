/* 
 * File:   WeightsTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 12:16 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Weights.h"

namespace {

    class WeightsTest : public ::testing::Test {
    protected:

        WeightsTest() {
            size = 5;
            weights = new Weights(size);
        }

        virtual ~WeightsTest() {
            delete weights;
        }
        int size;
        Weights *weights;
    };

    /*
     * Tests whether the <code>Weights</code> class extends 
     * <code>Vector</code> correctly.
     * 
     */
    TEST_F(WeightsTest, ExtensionTest) {
        EXPECT_EQ(size, weights->getSize());
    }

    /*
     * Tests whether an exception is thrown when the size is set to
     * zero.
     * 
     */
    TEST_F(WeightsTest, ExceptionTest) {
        EXPECT_THROW(new Weights(0), EmptyVectorException);
    }
}
