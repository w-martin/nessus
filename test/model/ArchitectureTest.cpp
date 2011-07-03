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
            outputFunctionMock = new MockOutputFunction();
            trainer = new Trainer();
            auto_ptr<OutputFunction> outputFunctionPointer(outputFunctionMock);
            auto_ptr<Trainer> trainerPointer(trainer);
            architecture = new Architecture(noLayers, outputFunctionPointer,
                    trainerPointer);
        }

        virtual ~ArchitectureTest() {
            delete architecture;
        }
        int noLayers;
        Architecture *architecture;
        OutputFunction *outputFunctionMock;
        Trainer *trainer;
    };

    /*
     * Tests whether the constructor throws an exception when the arguments
     * are not initialized.
     * 
     */
    TEST_F(ArchitectureTest, ConstructorExceptionTest) {
        auto_ptr<OutputFunction> outputFunctionPointer(
                new MockOutputFunction());
        auto_ptr<Trainer> trainerPointer(new Trainer());

        auto_ptr<OutputFunction> tmp1;
        EXPECT_THROW(new Architecture(0,
                tmp1, trainerPointer),
                IllegalArgumentException);

        auto_ptr<Trainer> tmp2;
        EXPECT_THROW(new Architecture(0,
                outputFunctionPointer, tmp2),
                IllegalArgumentException);
    }

    /*
     * Tests whether the maximum number of layers is returned correctly.
     * 
     */
    TEST_F(ArchitectureTest, GetMaxLayersTest) {
        EXPECT_EQ(noLayers, architecture->getMaxLayers());
    }

    /*
     * Tests whether the function is returned correctly.
     * 
     */
    TEST_F(ArchitectureTest, GetFunctionTest) {
        EXPECT_EQ(outputFunctionMock, architecture->getFunction());
    }

    /*
     * Tests whether the trainer is returned correctly.
     * 
     */
    TEST_F(ArchitectureTest, GetTrainerTest) {
        EXPECT_EQ(trainer, architecture->getTrainer());
    }
}
