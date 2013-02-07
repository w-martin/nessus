/*
 * File:   BDNTest.cpp
 * Author: will
 *
 * Created on 10th July 2011, 16:46
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/nets/BDN/BDN.h"
#include "nn-simulator/test/functions/MockOutputFunction.h"
#include "nn-simulator/test/model/MockInput.h"
#include "nn-simulator/test/model/MockOutput.h"

using ::testing::Return;

namespace {

    class BDNTest : public ::testing::Test {
    protected:

        BDNTest() {
            size = 1;
            outputFunctionMock = new MockOutputFunction();
            bdn = new BDN(size, outputFunctionMock);
        }

        virtual ~BDNTest() {
            delete bdn;
            delete outputFunctionMock;
        }
        int size;
        MockOutputFunction *outputFunctionMock;
        BDN *bdn;
    };

    /*
     * Tests whether the parent constructor is called
     * correctly.
     *
     */
    TEST_F(BDNTest, ConstructorTest) {
        EXPECT_EQ(size, bdn->getWeights()->getSize());
        EXPECT_EQ(outputFunctionMock, bdn->getOutputFunction());
    }

    /*
     * Tests whether the type is returned correctly.
     *
     */
    TEST_F(BDNTest, GetTypeTest) {
        EXPECT_EQ(0, strcmp(NEURON_TYPE_BDN, bdn->getType()));
    }

    /*
     * Tests whether the threshold getter and setter
     * work correctly.
     *
     */
    TEST_F(BDNTest, ThresholdTest) {
        float expected = 0.54f;
        bdn->setThreshold(expected);
        EXPECT_EQ(expected, bdn->getThreshold());
    }

    /*
     * Tests whether the expected input getter and setter
     * work correctly.
     *
     */
    TEST_F(BDNTest, ExpectedInputTest) {
        MockInput *inputMock = new MockInput();
        bdn->setExpectedInput(auto_ptr<Input > (inputMock));
        EXPECT_EQ(inputMock, bdn->getExpectedInput());
    }

    /*
     * Tests whether the necessary input getter and setter
     * work correctly.
     *
     */
    TEST_F(BDNTest, NecessaryInputTest) {
        MockInput *inputMock = new MockInput();
        bdn->setNecessaryInput(auto_ptr<Input > (inputMock));
        EXPECT_EQ(inputMock, bdn->getNecessaryInput());
    }

    /*
     * Tests whether the necessary input getter and setter
     * work correctly.
     *
     */
    TEST_F(BDNTest, CalculateActivationTest) {
        MockInput inputMock = MockInput();
        float threshold = 0.0f;
        MockOutput outputMock = MockOutput();
        bdn->setThreshold(threshold);
        EXPECT_CALL((*outputFunctionMock), function(_))
                .WillOnce(Return(outputMock));
        EXPECT_EQ(outputMock.getValue(),
                bdn->processInput(inputMock).getValue());
    }
}
