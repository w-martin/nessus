/*
 * File:   HeavisideFunctionTest.cpp
 * Author: Will
 *
 * Created on 29 June 2011, 23:20
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FunctionTests

#include <boost/test/unit_test.hpp>
#include "nessus/functions/HeavisideFunction.h"
#include "nessus/model/Output.h"

struct HeavisideFunctionTest {

  HeavisideFunctionTest() {
    heavisideFunction = new HeavisideFunction();
  }

  virtual ~HeavisideFunctionTest() {
    delete heavisideFunction;
  }
  HeavisideFunction *heavisideFunction;
};

BOOST_FIXTURE_TEST_SUITE(HeavisideFunctionTests, HeavisideFunctionTest)

/**
 * Tests whether the function method works correctly.
 *
 */
BOOST_AUTO_TEST_CASE(TestFunction) {
  BOOST_CHECK_EQUAL(0.0f, heavisideFunction->function(-1).getValue());
  BOOST_CHECK_EQUAL(1.0f, heavisideFunction->function(1).getValue());
}

BOOST_AUTO_TEST_SUITE_END()
