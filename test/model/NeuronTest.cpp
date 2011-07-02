/* 
 * File:   NeuronTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 10:04 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/test/functions/MockOutputFunction.h"

namespace {

    class NeuronTest : public ::testing::Test {
    protected:

        NeuronTest() {
            size = 1;
            weights = new Weights(size);
            auto_ptr<Weights> tmp(weights);
            outputFunctionMock = new MockOutputFunction();
            neuron = new Neuron(tmp, outputFunctionMock);
        }

        virtual ~NeuronTest() {
            delete neuron;
        }
        int size;
        Weights *weights;
        MockOutputFunction *outputFunctionMock;
        Neuron *neuron;
    };

    /*
     * Tests whether the constructor throws an exception given
     * a null input.
     * 
     */
    TEST_F(NeuronTest, ConstructorExceptionTest) {
        auto_ptr<Weights> w;
        EXPECT_THROW(new Neuron(w, outputFunctionMock),
                IllegalArgumentException*);
        
        weights = new Weights(size);
        w = auto_ptr<Weights> (weights);
        EXPECT_THROW(new Neuron(w, NULL),
                IllegalArgumentException*);
    }

    /*
     * Tests whether the getWeights method returns the weights correctly.
     * 
     */
    TEST_F(NeuronTest, GetWeightsTest) {
        EXPECT_EQ(weights, neuron->getWeights());
    }

    /*
     * Tests whether the getOutputFunction method returns the output function
     * correctly.
     * 
     */
    TEST_F(NeuronTest, GetOutputFunctionTest) {
        EXPECT_EQ(outputFunctionMock, neuron->getOutputFunction());
    }
}
