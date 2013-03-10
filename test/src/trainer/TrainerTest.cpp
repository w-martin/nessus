/*
 * File:   TrainerTest.cpp
 * Author: will
 *
 * Created on 8th July 2011, 23:31
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TrainerTests

#include <boost/test/unit_test.hpp>
#include "nessus/trainer/Trainer.h"
#include "nessus/model/MockNeuron.h"

struct TrainerTest {

  TrainerTest() {
    trainer = new Trainer();
  }

  virtual ~TrainerTest() {
    delete trainer;
  }
  Trainer *trainer;
};

BOOST_FIXTURE_TEST_SUITE(TrainerTests, TrainerTest)

/*
 * Tests whether the getValue method returns the correct
 * value.
 *
 */
BOOST_AUTO_TEST_CASE(InitWeightsTest) {
  MockNeuron *neuronMock = new MockNeuron();
  trainer->initWeights(neuronMock);

  Weights *weights = neuronMock->getWeights();
  for (int i = 0; i < weights->getSize(); i++) {
    BOOST_CHECK_LT(weights->getValue(i), 1.0f);
    BOOST_CHECK_GT(weights->getValue(i), 0.0f);
  }
}

BOOST_AUTO_TEST_SUITE_END()
