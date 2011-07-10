/* 
 * File:   NeuronTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 10:04 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/test/functions/MockOutputFunction.h"
#include "nn-simulator/test/model/MockOutput.h"

#define NEURON_TYPE_TEST "test neuron type"

using ::testing::Return;

namespace {

    class NeuronTest : public ::testing::Test {
    protected:

        NeuronTest() {
            size = 1;
            outputFunctionMock = new MockOutputFunction();
            neuron = new Neuron(size, outputFunctionMock, NEURON_TYPE_TEST);
        }

        virtual ~NeuronTest() {
            delete neuron;
            delete outputFunctionMock;
        }
        int size;
        MockOutputFunction *outputFunctionMock;
        Neuron *neuron;
    };

    /*
     * Tests whether the constructor throws an exception given
     * a null input.
     * 
     */
    TEST_F(NeuronTest, ConstructorExceptionTest) {
        EXPECT_THROW(new Neuron(0, outputFunctionMock, NEURON_TYPE_TEST),
                IllegalArgumentException);

        EXPECT_THROW(new Neuron(size, NULL, NEURON_TYPE_TEST),
                IllegalArgumentException);
    }

    /*
     * Tests whether the getWeights method returns the weights correctly.
     * 
     */
    TEST_F(NeuronTest, GetWeightsTest) {
        EXPECT_EQ(size, neuron->getWeights()->getSize());
    }

    /*
     * Tests whether the getType method returns the type correctly.
     * 
     */
    TEST_F(NeuronTest, GetTypeTest) {
        EXPECT_STREQ(NEURON_TYPE_TEST, neuron->getType());
    }

    /*
     * Tests whether the input is processed correctly.
     * 
     */
    TEST_F(NeuronTest, ProcessInputTest) {
        EXPECT_CALL((*outputFunctionMock), function(1))
                .WillOnce(Return(MockOutput()));
        Input input(1);
        input.setValue(0, 1.0f);
        neuron->processInput(input);
    }

    /*
     * Tests whether the expected output getter and setter work correctly.
     * 
     */
    TEST_F(NeuronTest, ExpectedOutputTest) {
        EXPECT_EQ(NULL, neuron->getExpectedOutput());

        Output *outputMock = new MockOutput();
        auto_ptr<Output> pOutput(outputMock);
        neuron->setExpectedOutput(pOutput);
        EXPECT_EQ(outputMock, neuron->getExpectedOutput());
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
