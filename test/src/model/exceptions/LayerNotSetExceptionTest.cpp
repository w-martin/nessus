/*
 * File:   LayerNotSetExceptionTest.cpp
 * Author: will
 *
 * Created on 8th July 2011, 11:24 PM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/model/exceptions/LayerNotSetException.h"

#define message "test message"

struct LayerNotSetExceptionTest {

  LayerNotSetExceptionTest() {
    testException = new LayerNotSetException(message);
  }

  ~LayerNotSetExceptionTest() {
    delete testException;
  }
  LayerNotSetException *testException;
};

BOOST_FIXTURE_TEST_SUITE(LayerNotSetExceptionTests, LayerNotSetExceptionTest)

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
  testException = new LayerNotSetException();

  BOOST_CHECK_EQUAL(LAYER_NOT_SET_MESSAGE, testException->what());
}

BOOST_AUTO_TEST_SUITE_END()
