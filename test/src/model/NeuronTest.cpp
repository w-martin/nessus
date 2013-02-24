/* 
 * File:   NeuronTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 10:04 AM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/model/Neuron.h"
#include "nessus/functions/MockOutputFunction.h"
#include "nessus/model/MockOutput.h"

#define NEURON_TYPE_TEST "test neuron type"

struct NeuronTest {

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

BOOST_FIXTURE_TEST_SUITE(NeuronTests, NeuronTest)

/*
 * Tests whether the constructor throws an exception given
 * a null input.
 * 
 */
BOOST_AUTO_TEST_CASE(ConstructorExceptionTest) {
  BOOST_CHECK_THROW(new Neuron(0, outputFunctionMock, NEURON_TYPE_TEST),
          IllegalArgumentException);

  BOOST_CHECK_THROW(new Neuron(size, NULL, NEURON_TYPE_TEST),
          IllegalArgumentException);
}

/*
 * Tests whether the getWeights method returns the weights correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(GetWeightsTest) {
  BOOST_CHECK_EQUAL(size, neuron->getWeights()->getSize());
}

/*
 * Tests whether the getType method returns the type correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(GetTypeTest) {
  BOOST_CHECK_EQUAL(NEURON_TYPE_TEST, neuron->getType());
}

/*
 * Tests whether the input is processed correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(ProcessInputTest) {
  //    EXPECT_CALL((*outputFunctionMock), function(1))
  //            .WillOnce(Return(MockOutput()));
  Input input(1);
  input.setValue(0, 1.0f);
  neuron->processInput(input);
}

/*
 * Tests whether the expected output getter and setter work correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(ExpectedOutputTest) {
  BOOST_CHECK_EQUAL((void*) NULL, neuron->getExpectedOutput());

  Output *outputMock = new MockOutput();
  auto_ptr<Output> pOutput(outputMock);
  neuron->setExpectedOutput(pOutput);
  BOOST_CHECK_EQUAL(outputMock, neuron->getExpectedOutput());
}

/*
 * Tests whether the getOutputFunction method returns the output function
 * correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(GetOutputFunctionTest) {
  BOOST_CHECK_EQUAL(outputFunctionMock, neuron->getOutputFunction());
}

BOOST_AUTO_TEST_SUITE_END()
