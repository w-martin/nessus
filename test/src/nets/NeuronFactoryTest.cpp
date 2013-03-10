/*
 * File:   NeuronFactoryTest.cpp
 * Author: will
 *
 * Created on July 16, 2011, 11:17 AM
 */

#include <boost/test/unit_test.hpp>
#include "nessus/nets/NeuronFactory.h"
#include "nessus/util/exceptions/UnsupportedConfigurationException.h"
#include "nessus/nets/BDN/BDN.h"
#include "nessus/model/MockArchitecture.h"
#include "nessus/nets/BDN/LogicalArchitecture.h"

#define TEST_NEURON_TYPE "test net type"

struct NeuronFactoryTest {

  NeuronFactoryTest() {
    size = 1;
  }

  virtual ~NeuronFactoryTest() {
  }
  int size;
  MockArchitecture architectureMock;
  LogicalArchitecture logicalArchitecture;
};

auto_ptr<Neuron> createNeuronInstance(const Architecture &architecture,
                                      const int &size)
throw (UnsupportedConfigurationException) {
  return Factory<Neuron, Architecture>::createInstance(architecture,
         size);
}

auto_ptr<BDN> createBDNInstance(const Architecture &architecture,
                                const int &size)
throw (UnsupportedConfigurationException) {
  return Factory<BDN, Architecture>::createInstance(architecture,
         size);
}

BOOST_FIXTURE_TEST_SUITE(NeuronFactoryTests, NeuronFactoryTest)

/*
 * Tests whether the createInstance method works correctly
 * given various neuron configurations.
 *
 */
BOOST_AUTO_TEST_CASE(CreateNeuronInstanceTest) {
  BOOST_CHECK_THROW(createNeuronInstance(architectureMock, size),
                    UnsupportedConfigurationException);

  auto_ptr<Neuron> neuron = createNeuronInstance(logicalArchitecture,
                            size);
  BOOST_CHECK(neuron.get());
  BOOST_CHECK_EQUAL(size, neuron->getWeights()->getSize());
  BOOST_CHECK_EQUAL(0, strcmp(NEURON_TYPE_BDN, neuron->getType()));
}

/*
 * Tests whether the createInstance method works correctly
 * given the BDN configuration.
 *
 */
BOOST_AUTO_TEST_CASE(CreateBDNInstanceTest) {
  BOOST_CHECK_THROW(createBDNInstance(architectureMock, size),
                    UnsupportedConfigurationException);

  auto_ptr<BDN> bdn = createBDNInstance(logicalArchitecture,
                                        size);
  BOOST_CHECK(bdn.get());
  BOOST_CHECK_EQUAL(size, bdn->getWeights()->getSize());
  BOOST_CHECK_EQUAL(0, strcmp(NEURON_TYPE_BDN, bdn->getType()));
}

BOOST_AUTO_TEST_SUITE_END()
