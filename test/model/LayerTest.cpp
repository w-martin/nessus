/* 
 * File:   LayerTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 5:56 PM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Layer.h"
#include "nn-simulator/test/model/MockNeuron.h"

namespace {

    class LayerTest : public ::testing::Test {
    protected:

        LayerTest() {
            size = 1;
            adaptiveWeights = true;
            layer = new Layer(size, adaptiveWeights);
        }

        virtual ~LayerTest() {
            delete layer;
        }
        int size;
        bool adaptiveWeights;
        Layer *layer;
    };

    /*
     * Tests whether size is returned correctly.
     * 
     */
    TEST_F(LayerTest, GetSizeTest) {
        ASSERT_EQ(size, layer->getSize());
    }

    /*
     * Tests whether the Neuron getter and setter work correctly.
     * 
     */
    TEST_F(LayerTest, NeuronTest) {
        EXPECT_EQ(NULL, layer->getNeuron(0));

        Neuron *neuron = new MockNeuron();
        auto_ptr<Neuron> neuronPointer(neuron);
        layer->setNeuron(0, neuronPointer);
        EXPECT_EQ(neuron, layer->getNeuron(0));
    }
}
