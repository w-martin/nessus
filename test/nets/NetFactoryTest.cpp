/* 
 * File:   NetFactoryTest.cpp
 * Author: will
 * 
 * Created on July 16, 2011, 11:17 AM
 */

#define TEST_NET_TYPE "test net type"

#include "gtest/gtest.h"
#include "nn-simulator/main/nets/NetFactory.h"
#include "nn-simulator/main/util/exceptions/UnsupportedConfigurationException.h"
#include "nn-simulator/main/nets/BDN/realisations/ORnet.h"

namespace {

    class NetFactoryTest : public ::testing::Test {
    protected:

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

    /*
     * Tests whether the createInstance method works correctly
     * given a net configuration.
     *
     */
    TEST_F(NetFactoryTest, CreateInstanceTest) {
        EXPECT_THROW(createInstance(TEST_NET_TYPE, size),
                UnsupportedConfigurationException);

        auto_ptr<Net> net = createInstance(NET_TYPE_ORNET, size);
        EXPECT_TRUE(net.get());
        EXPECT_EQ(size, net->getNoInputs());
        EXPECT_EQ(NET_TYPE_ORNET, net->getNetType());
    }
}
