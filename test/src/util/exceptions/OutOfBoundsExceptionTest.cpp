/*
 * File:   OutOfBoundsExceptionTest.cpp
 * Author: will
 *
 * Created on July 2, 2011, 9:58 AM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/util/exceptions/OutOfBoundsException.h"

#define message "test message"

struct OutOfBoundsExceptionTest {

  OutOfBoundsExceptionTest() {
    testException = new OutOfBoundsException(message);
  }

  virtual ~OutOfBoundsExceptionTest() {
    delete testException;
  }
  OutOfBoundsException *testException;
};

BOOST_FIXTURE_TEST_SUITE(OutOfBoundsExceptionTests, OutOfBoundsExceptionTest)

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
  testException = new OutOfBoundsException();

  BOOST_CHECK_EQUAL(OUT_OF_BOUNDS_MESSAGE, testException->what());
}

BOOST_AUTO_TEST_SUITE_END()
