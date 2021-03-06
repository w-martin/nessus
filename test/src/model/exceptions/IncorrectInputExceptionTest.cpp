/*
 * File:   IncorrectInputExceptionTest.cpp
 * Author: will
 *
 * Created on July 2, 2011, 1:01 AM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/model/exceptions/IncorrectInputException.h"

#define message "test message"

struct IncorrectInputExceptionTest {

  IncorrectInputExceptionTest() {
    testException = new IncorrectInputException(message);
  }

  virtual ~IncorrectInputExceptionTest() {
    delete testException;
  }
  IncorrectInputException *testException;
};

BOOST_FIXTURE_TEST_SUITE(IncorrectInputExceptionTests,
                         IncorrectInputExceptionTest)

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
  testException = new IncorrectInputException();

  BOOST_CHECK_EQUAL(INCORRECT_INPUT_MESSAGE, testException->what());
}

BOOST_AUTO_TEST_SUITE_END()
