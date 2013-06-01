/*
 * File:   LayerTest.cpp
 * Author: will
 *
 * Created on July 2, 2011, 5:56 PM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/model/Layer.h"
#include "nessus/model/MockNeuron.h"
#include "nessus/model/MockOutput.h"

struct LayerTest {

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

BOOST_FIXTURE_TEST_SUITE(LayerTests, LayerTest)

/*
 * Tests whether size is returned correctly.
 *
 */
BOOST_AUTO_TEST_CASE(GetSizeTest) {
  BOOST_CHECK_EQUAL(size, layer->getSize());
}

/*
 * Tests whether the Neuron getter and setter work correctly.
 *
 */
BOOST_AUTO_TEST_CASE(NeuronTest) {
  BOOST_CHECK_EQUAL((void*) NULL, layer->getNeuron(0));

  unique_ptr<Neuron> neuronPointer(neuronMock);
  layer->setNeuron(0, neuronPointer);
  BOOST_CHECK_EQUAL(neuronMock, layer->getNeuron(0));
}

/*
 * Tests whether the hasAdaptiveWeights method returns the correct
 * boolean.
 *
 */
BOOST_AUTO_TEST_CASE(HasAdaptiveWeightsTest) {
  BOOST_CHECK_EQUAL(adaptiveWeights, layer->hasAdaptiveWeights());
}

/*
 * Tests whether the processInput method works correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ProcessLayerTest) {
  Input input(1);
  //    EXPECT_CALL((*neuronMock), processInput(_))
  //            .WillOnce(Return((*outputMock)));

  unique_ptr<Neuron> neuronPointer(neuronMock);
  layer->setNeuron(0, neuronPointer);
  Input processedInput = layer->processInput(input);
  BOOST_CHECK_EQUAL(MockOutput().getValue(), processedInput.getValue(0));
}

BOOST_AUTO_TEST_SUITE_END()
