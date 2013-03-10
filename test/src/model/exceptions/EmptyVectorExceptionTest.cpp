/*
 * File:   EmptyVectorExceptionTest.cpp
 * Author: will
 *
 * Created on July 2, 2011, 12:55 AM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/model/exceptions/EmptyVectorException.h"

#define message "test message"

struct EmptyVectorExceptionTest {

  EmptyVectorExceptionTest() {
    testException = new EmptyVectorException(message);
  }

  virtual ~EmptyVectorExceptionTest() {
    delete testException;
  }
  EmptyVectorException *testException;
};

BOOST_FIXTURE_TEST_SUITE(EmptyVectorExceptionTests, EmptyVectorExceptionTest)

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
  testException = new EmptyVectorException();

  BOOST_CHECK_EQUAL(EMPTY_VECTOR_MESSAGE, testException->what());
}

BOOST_AUTO_TEST_SUITE_END()
