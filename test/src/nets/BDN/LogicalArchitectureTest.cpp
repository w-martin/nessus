/* 
 * File:   LogicalArchitectureTest.cpp
 * Author: will
 * 
 * Created on July 12, 2011, 11:15 PM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/nets/BDN/LogicalArchitecture.h"
#include "nn-simulator/main/nets/BDN/BDNTrainer.h"
#include "nn-simulator/main/functions/HeavisideFunction.h"

namespace {

    class LogicalArchitectureTest : public ::testing::Test {
    protected:

        LogicalArchitectureTest() {
            logicalArchitecture = new LogicalArchitecture();
        }

        virtual ~LogicalArchitectureTest() {
            delete logicalArchitecture;
        }

        LogicalArchitecture *logicalArchitecture;
    };

    /*
     * Tests whether the parent constructor is called
     * correctly.
     *
     */
    TEST_F(LogicalArchitectureTest, ConstructorTest) {
        EXPECT_EQ(0, logicalArchitecture->getMaxLayers());
        HeavisideFunction *function =
                (HeavisideFunction*) logicalArchitecture->getFunction();
        BDNTrainer *trainer =
                (BDNTrainer*) logicalArchitecture->getTrainer();
        EXPECT_EQ(0,
                strcmp(NEURON_TYPE_BDN, logicalArchitecture->getNeuronType()));
    }
}
