/* 
 * File:   ArchitectureTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 7:57 PM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Architecture.h"

using ::testing::Return;

namespace {

    class ArchitectureTest : public ::testing::Test {
    protected:

        ArchitectureTest() {
            
        }

        virtual ~ArchitectureTest() {
            delete Architecture;
        }
        int noLayers;
        Architecture *architecture;
        OutputFunction *outputFunction;
        Trainer *trainer;
    };

    /*
     * Tests whether size is returned correctly.
     * 
     */
    TEST_F(ArchitectureTest, GetSizeTest) {
        ASSERT_EQ(size, Architecture->getSize());
    }
}
