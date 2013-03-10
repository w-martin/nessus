/*
 * File:   UnsupportedConfigurationExceptionTest.cpp
 * Author: will
 *
 * Created on July 2, 2011, 9:57 AM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/util/exceptions/UnsupportedConfigurationException.h"

#define message "test message"

struct UnsupportedConfigurationExceptionTest {

  UnsupportedConfigurationExceptionTest() {
    testException = new UnsupportedConfigurationException(message);
  }

  virtual ~UnsupportedConfigurationExceptionTest() {
    delete testException;
  }
  UnsupportedConfigurationException *testException;
};

BOOST_FIXTURE_TEST_SUITE(UnsupportedConfigurationExceptionTests,
                         UnsupportedConfigurationExceptionTest)

/*
 * Tests whether the <code>Exception</code>'s message was set correctly.
 *
 */
BOOST_AUTO_TEST_CASE(MessageTest) {
  BOOST_CHECK_EQUAL(message, testException->what());
}

/*
 * Tests whether the default message is set correctly.
 *
 */
BOOST_AUTO_TEST_CASE(DefaultMessageTest) {
  delete testException;
  testException = new UnsupportedConfigurationException();

  BOOST_CHECK_EQUAL(UNSUPPORT_CONFIGURATION_MESSAGE, testException->what());
}

BOOST_AUTO_TEST_SUITE_END()
