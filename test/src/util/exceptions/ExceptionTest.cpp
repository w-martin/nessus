/*
 * File:   ExceptionTest.cpp
 * Author: will
 *
 * Created on July 2, 2011, 12:33 AM
 */


#include <boost/test/unit_test.hpp>
#include "nessus/util/exceptions/Exception.h"

#define message "test message"

struct ExceptionTest {

  ExceptionTest() {
    testException = new Exception(message);
  }

  virtual ~ExceptionTest() {
    delete testException;
  }
  Exception *testException;
};

BOOST_FIXTURE_TEST_SUITE(ExceptionTests, ExceptionTest)

/*
 * Tests whether the <code>Exception</code>'s message was set correctly.
 *
 */
BOOST_AUTO_TEST_CASE(MessageTest) {
  BOOST_CHECK_EQUAL(message, testException->what());
}

BOOST_AUTO_TEST_SUITE_END()
