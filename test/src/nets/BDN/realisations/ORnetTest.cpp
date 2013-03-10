/*
 * File:   ORnetTest.cpp
 * Author: will
 *
 * Created on July 14, 2011, 6:29 PM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/nets/BDN/realisations/ORnet.h"
#include "nessus/model/Input.h"
#include "nessus/nets/BDN/LogicalArchitecture.h"
#include "nessus/nets/BDN/BDN.h"

struct ORnetTest {

  ORnetTest() {
    noInputs = 1;
    net = new ORnet(noInputs);
  }

  virtual ~ORnetTest() {
    delete net;
  }

  int noInputs;
  ORnet *net;
};

BOOST_FIXTURE_TEST_SUITE(ORnetTests, ORnetTest)

/*
 * Tests whether the parent constructor is called
 * correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ConstructorTest) {
  BOOST_CHECK_EQUAL(noInputs, net->getNoInputs());
  BOOST_CHECK_EQUAL(1, net->getNoLayers());
  BOOST_CHECK_EQUAL(0, strcmp(NET_TYPE_ORNET, net->getNetType()));
  LogicalArchitecture *la = (LogicalArchitecture*)
                            net->getArchitecture();
  Layer *l = net->getLayer(0);
  BDN *bdn = (BDN*) l->getNeuron(0);
}

/*
 * Tests whether the function works correctly.
 *
 */
BOOST_AUTO_TEST_CASE(FunctionTest) {
  Input trueInput = Input(noInputs);
  for (int i = 0; i < noInputs; i++) {
    trueInput.setValue(i, 1.0f);
  }
  BOOST_CHECK_EQUAL(1.0f, net->processInput(trueInput).getValue());

  Input falseInput = Input(noInputs);
  for (int i = 0; i < noInputs; i++) {
    falseInput.setValue(i, 0.0f);
  }
  BOOST_CHECK_EQUAL(0.0f, net->processInput(falseInput).getValue());
}

BOOST_AUTO_TEST_SUITE_END()
