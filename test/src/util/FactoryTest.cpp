/* 
 * File:   FactoryTest.cpp
 * Author: will
 * 
 * Created on July 14, 2011, 10:24 PM
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE UtilTests

#include <boost/test/unit_test.hpp>
#include "nessus/util/Factory.h"
#include "nessus/util/exceptions/UnsupportedConfigurationException.h"

struct FactoryTest {

  FactoryTest() {
  }

  virtual ~FactoryTest() {
  }
};

void createInstance() throw (UnsupportedConfigurationException) {
  Factory<int, int>::createInstance(5);
}

void createInstanceSize() throw (UnsupportedConfigurationException) {
  Factory<int, int>::createInstance(5, 5);
}

BOOST_FIXTURE_TEST_SUITE(FactoryTests, FactoryTest)

/*
 * Tests whether the createInstance method works correctly
 * given a generic configuration.
 *
 */
BOOST_AUTO_TEST_CASE(CreateInstanceTest) {
  BOOST_CHECK_THROW(createInstance(),
          UnsupportedConfigurationException);
  BOOST_CHECK_THROW(createInstanceSize(),
          UnsupportedConfigurationException);
}

BOOST_AUTO_TEST_SUITE_END()
