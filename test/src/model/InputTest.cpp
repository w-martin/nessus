/*
 * File:   InputTest.cpp
 * Author: will
 *
 * Created on July 2, 2011, 12:25 AM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/model/Input.h"

struct InputTest {

  InputTest() {
    size = 5;
    input = new Input(size);
  }

  virtual ~InputTest() {
    delete input;
  }
  int size;
  Input *input;
};

BOOST_FIXTURE_TEST_SUITE(InputTests, InputTest)

/*
 * Tests whether the <code>Input</code> class extends
 * <code>Vector</code> correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ExtensionTest) {
  BOOST_CHECK_EQUAL(size, input->getSize());
}

/*
 * Tests whether an exception is thrown when the size is set to
 * zero.
 *
 */
BOOST_AUTO_TEST_CASE(ExceptionTest) {
  BOOST_CHECK_THROW(new Input(0), EmptyVectorException);
}

BOOST_AUTO_TEST_SUITE_END()
