/* 
 * File:   LayerTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 5:56 PM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Layer.h"
#include "nn-simulator/test/model/MockNeuron.h"
#include "nn-simulator/test/model/MockOutput.h"

using ::testing::Return;
using ::testing::_;

namespace {

    class LayerTest : public ::testing::Test {
    protected:

        LayerTest() {
            size = 1;
            adaptiveWeights = true;
            layer = new Layer(size, adaptiveWeights);
            neuronMock = new MockNeuron();
            outputMock = new MockOutput();
        }

        virtual ~LayerTest() {
            delete layer;
            delete neuronMock;
            delete outputMock;
        }
        int size;
        bool adaptiveWeights;
        Layer *layer;
        MockNeuron *neuronMock;
        MockOutput *outputMock;
    };

    /*
     * Tests whether size is returned correctly.
     * 
     */
    TEST_F(LayerTest, GetSizeTest) {
        EXPECT_EQ(size, layer->getSize());
    }

    /*
     * Tests whether the Neuron getter and setter work correctly.
     * 
     */
    TEST_F(LayerTest, NeuronTest) {
        EXPECT_EQ(NULL, layer->getNeuron(0));

        auto_ptr<Neuron> neuronPointer(neuronMock);
        layer->setNeuron(0, neuronPointer);
        EXPECT_EQ(neuronMock, layer->getNeuron(0));
    }

    /*
     * Tests whether the hasAdaptiveWeights method returns the correct
     * boolean.
     * 
     */
    TEST_F(LayerTest, HasAdaptiveWeightsTest) {
        EXPECT_EQ(adaptiveWeights, layer->hasAdaptiveWeights());
    }

    /*
     * Tests whether the processInput method works correctly.
     * 
     */
    TEST_F(LayerTest, ProcessInputTest) {
        Input input(1);
        EXPECT_CALL((*neuronMock), processInput(_))
                .WillOnce(Return((*outputMock)));
        
        auto_ptr<Neuron> neuronPointer(neuronMock);
        layer->setNeuron(0, neuronPointer);
        Input processedInput = layer->processInput(input);
        EXPECT_EQ(MockOutput().getValue(), processedInput.getValue(0));
    }
}
