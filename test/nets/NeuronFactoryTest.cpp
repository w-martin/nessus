/* 
 * File:   NeuronFactoryTest.cpp
 * Author: will
 * 
 * Created on July 16, 2011, 11:17 AM
 */

#define TEST_NEURON_TYPE "test net type"

#include "gtest/gtest.h"
#include "nn-simulator/main/nets/NeuronFactory.h"
#include "nn-simulator/main/util/exceptions/UnsupportedConfigurationException.h"
#include "nn-simulator/main/nets/BDN/BDN.h"
#include "nn-simulator/test/model/MockArchitecture.h"
#include "nn-simulator/main/nets/BDN/LogicalArchitecture.h"

namespace {

    class NeuronFactoryTest : public ::testing::Test {
    protected:

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

    /*
     * Tests whether the createInstance method works correctly
     * given various neuron configurations.
     *
     */
    TEST_F(NeuronFactoryTest, CreateNeuronInstanceTest) {
        EXPECT_THROW(createNeuronInstance(architectureMock, size),
                UnsupportedConfigurationException);

        auto_ptr<Neuron> neuron = createNeuronInstance(logicalArchitecture,
                size);
        EXPECT_TRUE(neuron.get());
        EXPECT_EQ(size, neuron->getWeights()->getSize());
        EXPECT_EQ(0, strcmp(NEURON_TYPE_BDN, neuron->getType()));
    }

    /*
     * Tests whether the createInstance method works correctly
     * given the BDN configuration.
     *
     */
    TEST_F(NeuronFactoryTest, CreateBDNInstanceTest) {
        EXPECT_THROW(createBDNInstance(architectureMock, size),
                UnsupportedConfigurationException);

        auto_ptr<BDN> bdn = createBDNInstance(logicalArchitecture,
                size);
        EXPECT_TRUE(bdn.get());
        EXPECT_EQ(size, bdn->getWeights()->getSize());
        EXPECT_EQ(0, strcmp(NEURON_TYPE_BDN, bdn->getType()));
    }
}
