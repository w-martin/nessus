/* 
 * File:   ArchitectureTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 7:57 PM
 */

#include <memory>

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Architecture.h"
#include "nn-simulator/test/functions/MockOutputFunction.h"

using ::testing::Return;

namespace {

    class ArchitectureTest : public ::testing::Test {
    protected:

        ArchitectureTest() {
            noLayers = 1;
            outputFunction = new MockOutputFunction();
            trainer = new Trainer();
            auto_ptr<OutputFunction> outputFunctionPointer(outputFunction);
            auto_ptr<Trainer> trainerPointer(trainer);
            architecture = new Architecture(noLayers, outputFunctionPointer,
                    trainerPointer);
        }

        virtual ~ArchitectureTest() {
            delete architecture;
        }
        int noLayers;
        Architecture *architecture;
        OutputFunction *outputFunction;
        Trainer *trainer;
    };

    /*
     * Tests whether the maximum number of layers is returned correctly.
     * 
     */
    TEST_F(ArchitectureTest, GetMaxLayersTest) {
        ASSERT_EQ(noLayers, architecture->getMaxLayers());
    }
}
