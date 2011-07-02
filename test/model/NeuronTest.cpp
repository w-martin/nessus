/* 
 * File:   NeuronTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 10:04 AM
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/test/functions/MockOutputFunction.h"

namespace {

    class NeuronTest : public ::testing::Test {
    protected:

        NeuronTest() {
            size = 1;
            weights = new Weights(size);
            neuron = new Neuron(weights, &outputFunctionMock);
        }

        virtual ~NeuronTest() {
            delete neuron;
        }
        int size;
        Weights *weights;
        MockOutputFunction outputFunctionMock;
        Neuron *neuron;
    };

    /*
     * Tests whether the constructor throws an exception given
     * a null input.
     * 
     */
    TEST_F(NeuronTest, ConstructorExceptionTest) {
        EXPECT_THROW(new Neuron(NULL, &outputFunctionMock),
                IllegalArgumentException*);
        EXPECT_THROW(new Neuron(weights, NULL),
                IllegalArgumentException*);
    }
}
