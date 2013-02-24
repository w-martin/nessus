/*
 * File:   BDNTest.cpp
 * Author: will
 *
 * Created on 10th July 2011, 16:46
 */

#include <boost/test/unit_test.hpp>
#include "nessus/nets/BDN/BDN.h"
#include "nessus/functions/MockOutputFunction.h"
#include "nessus/model/MockInput.h"
#include "nessus/model/MockOutput.h"

struct BDNTest {

  BDNTest() {
    size = 1;
    outputFunctionMock = new MockOutputFunction();
    bdn = new BDN(size, outputFunctionMock);
  }

  virtual ~BDNTest() {
    delete bdn;
    delete outputFunctionMock;
  }
  int size;
  MockOutputFunction *outputFunctionMock;
  BDN *bdn;
};

BOOST_FIXTURE_TEST_SUITE(BDNTests, BDNTest)

/*
 * Tests whether the parent constructor is called
 * correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ConstructorTest) {
  BOOST_CHECK_EQUAL(size, bdn->getWeights()->getSize());
  BOOST_CHECK_EQUAL(outputFunctionMock, bdn->getOutputFunction());
}

/*
 * Tests whether the type is returned correctly.
 *
 */
BOOST_AUTO_TEST_CASE(GetTypeTest) {
  BOOST_CHECK_EQUAL(0, strcmp(NEURON_TYPE_BDN, bdn->getType()));
}

/*
 * Tests whether the threshold getter and setter
 * work correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ThresholdTest) {
  float expected = 0.54f;
  bdn->setThreshold(expected);
  BOOST_CHECK_EQUAL(expected, bdn->getThreshold());
}

/*
 * Tests whether the expected input getter and setter
 * work correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ExpectedInputTest) {
  MockInput *inputMock = new MockInput();
  bdn->setExpectedInput(auto_ptr<Input > (inputMock));
  BOOST_CHECK_EQUAL(inputMock, bdn->getExpectedInput());
}

/*
 * Tests whether the necessary input getter and setter
 * work correctly.
 *
 */
BOOST_AUTO_TEST_CASE(NecessaryInputTest) {
  MockInput *inputMock = new MockInput();
  bdn->setNecessaryInput(auto_ptr<Input > (inputMock));
  BOOST_CHECK_EQUAL(inputMock, bdn->getNecessaryInput());
}

/*
 * Tests whether the necessary input getter and setter
 * work correctly.
 *
 */
BOOST_AUTO_TEST_CASE(CalculateActivationTest) {
  MockInput inputMock = MockInput();
  float threshold = 0.0f;
  MockOutput outputMock = MockOutput();
  bdn->setThreshold(threshold);
  //  EXPECT_CALL((*outputFunctionMock), function(_))
  //          .WillOnce(Return(outputMock));
  BOOST_CHECK_EQUAL(outputMock.getValue(),
          bdn->processInput(inputMock).getValue());
}

BOOST_AUTO_TEST_SUITE_END()
