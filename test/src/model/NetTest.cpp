/*
 * File:   NetTest.cpp
 * Author: Will
 *
 * Created on 02 July, 21:32
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ModelTests

#include <boost/test/unit_test.hpp>
#include "nessus/model/Net.h"
#include "nessus/model/MockArchitecture.h"
#include "nessus/model/MockLayer.h"

#define TEST_NET_TYPE "test net type"

struct NetTest {

  NetTest() {
    noLayers = 1;
    noInputs = 1;
    architectureMock = new MockArchitecture();
    net = new Net(auto_ptr<Architecture > (architectureMock),
                  noLayers, noInputs, TEST_NET_TYPE);
  }

  ~NetTest() {
    delete net;
  }
  int noLayers;
  int noInputs;
  MockArchitecture *architectureMock;
  Net *net;
  char *netType;
};

BOOST_FIXTURE_TEST_SUITE(NetTests, NetTest)

/*
 * Tests whether the throws exceptions correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ConstructorExceptionTest) {
  BOOST_CHECK_THROW(
    new Net(auto_ptr<Architecture > (NULL),
            noLayers, noInputs, TEST_NET_TYPE),
    IllegalArgumentException);
  BOOST_CHECK_THROW(
    new Net(auto_ptr<Architecture > (new MockArchitecture()),
            3, noInputs, TEST_NET_TYPE),
    UnsupportedConfigurationException);
}

/*
 * Tests whether the number of layers is returned correctly.
 *
 */
BOOST_AUTO_TEST_CASE(GetNoLayersTest) {
  BOOST_CHECK_EQUAL(noLayers, net->getNoLayers());
}

/*
 * Tests whether the net's type is returned correctly.
 *
 */
BOOST_AUTO_TEST_CASE(GetNetTypeTest) {
  BOOST_CHECK_EQUAL(TEST_NET_TYPE, net->getNetType());
}

/*
 * Tests whether the layer getter and setter work correctly.
 *
 */
BOOST_AUTO_TEST_CASE(LayerTest) {
  MockLayer *layerMock = new MockLayer();
  net->setLayer(0, auto_ptr<Layer > (layerMock));
  BOOST_CHECK_EQUAL(layerMock, net->getLayer(0));
}

/*
 * Tests whether the architecture is returned correctly.
 *
 */
BOOST_AUTO_TEST_CASE(GetArchitectureTest) {
  BOOST_CHECK_EQUAL(architectureMock, net->getArchitecture());
}

/*
 * Tests whether the number of inputs is returned correctly.
 *
 */
BOOST_AUTO_TEST_CASE(GetNoInputsTest) {
  BOOST_CHECK_EQUAL(noInputs, net->getNoInputs());
}

/*
 * Tests whether an input is processed correctly.
 *
 */
BOOST_AUTO_TEST_CASE(ProcessInputTest) {
  BOOST_CHECK_THROW(net->processInput(Input(2)),
                    IncorrectInputException);

  Input input = Input(1);
  float expected = 0.34f;
  input.setValue(0, expected);

  MockLayer *layerMock = new MockLayer();
  //    EXPECT_CALL((*layerMock), processInput(_))
  //            .WillOnce(Return(input));
  net->setLayer(0, auto_ptr<Layer > (layerMock));

  Output result = net->processInput(input);
  BOOST_CHECK_EQUAL(expected, result.getValue());
}

BOOST_AUTO_TEST_SUITE_END()
