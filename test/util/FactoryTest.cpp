/* 
 * File:   FactoryTest.cpp
 * Author: will
 * 
 * Created on July 14, 2011, 10:24 PM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/util/Factory.h"
#include "nn-simulator/main/util/exceptions/UnsupportedConfigurationException.h"

namespace {

    class FactoryTest : public ::testing::Test {
    protected:

        FactoryTest() {
        }

        virtual ~FactoryTest() {
        }
    };

    void createInstance() throw (UnsupportedConfigurationException) {
        Factory<int, int>::createInstance(5);
    }

    void createInstanceSize() throw (UnsupportedConfigurationException) {
        Factory<int, int>::createInstance(5, 5);
    }

    /*
     * Tests whether the createInstance method works correctly
     * given a generic configuration.
     *
     */
    TEST_F(FactoryTest, CreateInstanceTest) {
        EXPECT_THROW(createInstance(),
                UnsupportedConfigurationException);
        EXPECT_THROW(createInstanceSize(),
                UnsupportedConfigurationException);
    }
}
