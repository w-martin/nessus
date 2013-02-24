/* 
 * File:   SigmoidFunctionTest.cpp
 * Author: Will
 * 
 * Created on June 29, 2011, 11:38 PM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/functions/SigmoidFunction.h"
#include "nessus/model/Output.h"

struct SigmoidFunctionTest {

  SigmoidFunctionTest() {
    sigmoidFunction = new SigmoidFunction();
  }

  virtual ~SigmoidFunctionTest() {
    delete sigmoidFunction;
  }
  SigmoidFunction *sigmoidFunction;
};

BOOST_FIXTURE_TEST_SUITE(SigmoidFunctionTests, SigmoidFunctionTest)

/**
 * Tests whether the function method works correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(TestFunction) {
  float value;
  value = sigmoidFunction->function(0.0f).getValue();
  BOOST_CHECK_LT(0.0f, value);
  BOOST_CHECK_GT(1.0f, value);
  value = sigmoidFunction->function(1.0f).getValue();
  BOOST_CHECK_LT(0.0f, value);
  BOOST_CHECK_GT(1.0f, value);
}

/**
 * Tests whether the derivative method works correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(TestDerivative) {
  float value;
  value = sigmoidFunction->function(0.5f).getValue();
  value = value * (1.0f - value);
  BOOST_CHECK_EQUAL(value, sigmoidFunction->derivative(0.5f).getValue());
}

BOOST_AUTO_TEST_SUITE_END()
