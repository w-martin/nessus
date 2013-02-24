/* 
 * File:   IllegalArgumentExceptionTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 9:59 AM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/util/exceptions/IllegalArgumentException.h"

#define message "test message"

struct IllegalArgumentExceptionTest {

  IllegalArgumentExceptionTest() {
    testException = new IllegalArgumentException(message);
  }

  virtual ~IllegalArgumentExceptionTest() {
    delete testException;
  }
  IllegalArgumentException *testException;
};

BOOST_FIXTURE_TEST_SUITE(IllegalArgumentExceptionTests,
        IllegalArgumentExceptionTest)

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
  testException = new IllegalArgumentException();

  BOOST_CHECK_EQUAL(ILLEGAL_ARGUMENT_MESSAGE, testException->what());
}

BOOST_AUTO_TEST_SUITE_END()
