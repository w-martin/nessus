/*
 * File:   LogicalArchitectureTest.cpp
 * Author: will
 *
 * Created on July 12, 2011, 11:15 PM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/nets/BDN/LogicalArchitecture.h"
#include "nessus/nets/BDN/BDNTrainer.h"
#include "nessus/functions/HeavisideFunction.h"

struct LogicalArchitectureTest {

  LogicalArchitectureTest() {
    logicalArchitecture = new LogicalArchitecture();
  }

  virtual ~LogicalArchitectureTest() {
    delete logicalArchitecture;
  }

  LogicalArchitecture *logicalArchitecture;
};

BOOST_FIXTURE_TEST_SUITE(LogicalArchitectureTests, LogicalArchitectureTest)

/*
 * Tests whether the parent constructor is called
 * correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ConstructorTest) {
  BOOST_CHECK_EQUAL(0, logicalArchitecture->getMaxLayers());
  HeavisideFunction *function =
    (HeavisideFunction*) logicalArchitecture->getFunction();
  BDNTrainer *trainer =
    (BDNTrainer*) logicalArchitecture->getTrainer();
  BOOST_CHECK_EQUAL(0,
                    strcmp(NEURON_TYPE_BDN, logicalArchitecture->getNeuronType()));
}

BOOST_AUTO_TEST_SUITE_END()
