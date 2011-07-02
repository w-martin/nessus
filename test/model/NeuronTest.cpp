/* 
 * File:   NeuronTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 10:04 AM
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/test/functions/OutputFunctionMock.h"

namespace {

    class NeuronTest : public ::testing::Test {
    protected:

        NeuronTest() {
            size = 1;
            weights = new Weights(size);
            outputFunction = new HeavisideFunction();
        }

        virtual ~NeuronTest() {
            delete neuron;
        }
        int size;
        Weights *weights;
        OutputFunction *outputFunction;
        Neuron *neuron;
    };

    /*
     * Tests whether the <code>Neuron</code> class extends 
     * <code>Vector</code> correctly.
     * 
     */
    TEST_F(NeuronTest, ExtensionTest) {
        ASSERT_EQ(size, neuron->getSize());
    }
}
