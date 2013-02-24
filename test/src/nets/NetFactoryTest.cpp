/* 
 * File:   NetFactoryTest.cpp
 * Author: will
 * 
 * Created on July 16, 2011, 11:17 AM
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE NetTests

#include <boost/test/unit_test.hpp>
#include "nessus/nets/NetFactory.h"
#include "nessus/util/exceptions/UnsupportedConfigurationException.h"
#include "nessus/nets/BDN/realisations/ORnet.h"

#define TEST_NET_TYPE "test net type"

struct NetFactoryTest {

  NetFactoryTest() {
    size = 1;
  }

  virtual ~NetFactoryTest() {
  }
  int size;
};

auto_ptr<Net> createInstance(const char * const netType,
        const int &size)
throw (UnsupportedConfigurationException) {
  return Factory<Net, const char *>::createInstance(netType, size);
}

BOOST_FIXTURE_TEST_SUITE(NetFactoryTests, NetFactoryTest)

/*
 * Tests whether the createInstance method works correctly
 * given a net configuration.
 *
 */
BOOST_AUTO_TEST_CASE(CreateInstanceTest) {
  BOOST_CHECK_THROW(createInstance(TEST_NET_TYPE, size),
          UnsupportedConfigurationException);

  auto_ptr<Net> net = createInstance(NET_TYPE_ORNET, size);
  BOOST_CHECK(net.get());
  BOOST_CHECK_EQUAL(size, net->getNoInputs());
  BOOST_CHECK_EQUAL(0, strcmp(NET_TYPE_ORNET, net->getNetType()));
}

BOOST_AUTO_TEST_SUITE_END()
