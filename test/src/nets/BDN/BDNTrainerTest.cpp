/* 
 * File:   BDNTrainerTest.cpp
 * Author: will
 * 
 * Created on July 14, 2011, 8:21 PM
 */

#include <boost/test/unit_test.hpp>
#include "nn-simulator/main/nets/BDN/BDNTrainer.h"
#include "nn-simulator/main/nets/BDN/BDN.h"
#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/test/nets/BDN/MockBDN.h"
#include "nn-simulator/test/model/MockNeuron.h"
#include "nn-simulator/test/model/MockInput.h"
#include "nn-simulator/test/model/MockOutput.h"

struct BDNTrainerTest {

  BDNTrainerTest() {
    trainer = new BDNTrainer();
    bdnMock = new MockBDN();
    MockInput *expectedInput = new MockInput();
    MockInput *necessaryInput = new MockInput();
    MockOutput *expectedOutput = new MockOutput();
    bdnMock->setExpectedInput(auto_ptr<Input > (expectedInput));
    bdnMock->setNecessaryInput(auto_ptr<Input > (necessaryInput));
    bdnMock->setExpectedOutput(auto_ptr<Output > (expectedOutput));
  }

  virtual ~BDNTrainerTest() {
    delete trainer;
    delete bdnMock;
  }
  BDNTrainer *trainer;
  MockBDN *bdnMock;
};

BOOST_FIXTURE_TEST_SUITE(BDNTrainerTests, BDNTrainerTest)

/*
 * Tests whether the weights of a <code>Neuron</code> are
 * left unchanged if it is not a <code>BDN</code>.
 *
 */
BOOST_AUTO_TEST_CASE(InitWeightsTest) {
  MockNeuron *neuronMock = new MockNeuron();

  //  EXPECT_CALL(*(neuronMock), getType())
  //          .WillOnce(Return(NEURON_TYPE_MOCK));
  float expected = neuronMock->getWeights()->getValue(0);
  trainer->initWeights(neuronMock);
  BOOST_CHECK_EQUAL(expected, neuronMock->getWeights()->getValue(0));

  delete neuronMock;
}

/*
 * Tests whether the weights of a <code>BDN</code> are
 * initialized correctly.
 *
 */
BOOST_AUTO_TEST_CASE(InitWeightsBDNTest) {
  //  EXPECT_CALL(*(bdnMock), getType())
  //          .WillOnce(Return(NEURON_TYPE_BDN));
  trainer->initWeights(bdnMock);
  Weights *w = bdnMock->getWeights();
  for (int i = 0; i < w->getSize(); i++) {
    BOOST_CHECK_EQUAL(1.0f, w->getValue(i));
  }
}

/*
 * Tests whether the threshold is set correctly.
 *
 */
BOOST_AUTO_TEST_CASE(SetThresholdTest) {
  trainer->setThreshold(bdnMock);
  BOOST_CHECK_EQUAL(0.5f, bdnMock->getThreshold());
}

BOOST_AUTO_TEST_SUITE_END()
