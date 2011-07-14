/* 
 * File:   BDNTrainerTest.cpp
 * Author: will
 * 
 * Created on July 14, 2011, 8:21 PM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/nets/BDN/BDNTrainer.h"
#include "nn-simulator/main/nets/BDN/BDN.h"
#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/test/nets/BDN/MockBDN.h"
#include "nn-simulator/test/model/MockNeuron.h"
#include "nn-simulator/test/model/MockInput.h"
#include "nn-simulator/test/model/MockOutput.h"

using ::testing::Return;

namespace {

    class BDNTrainerTest : public ::testing::Test {
    protected:

        BDNTrainerTest() {
            trainer = new BDNTrainer();
            bdnMock = new MockBDN();
            MockInput *expectedInput = new MockInput();
            MockInput *necessaryInput = new MockInput();
            MockOutput *expectedOutput = new MockOutput();
            bdnMock->setExpectedInput(auto_ptr<Input > (expectedInput));
            bdnMock->setNecessaryInput(auto_ptr<Input > (necessaryInput));
            bdnMock->setExpectedOutput(auto_ptr<Output > (expectedOutput));
        }

        virtual ~BDNTrainerTest() {
            delete trainer;
            delete bdnMock;
        }
        BDNTrainer *trainer;
        MockBDN *bdnMock;
    };

    /*
     * Tests whether the weights of a <code>Neuron</code> are
     * left unchanged if it is not a <code>BDN</code>.
     *
     */
    TEST_F(BDNTrainerTest, InitWeightsTest) {
        MockNeuron *neuronMock = new MockNeuron();
        
        EXPECT_CALL(*(neuronMock), getType())
                .WillOnce(Return(NEURON_TYPE_MOCK));
        float expected = neuronMock->getWeights()->getValue(0);
        trainer->initWeights(neuronMock);
        EXPECT_EQ(expected, neuronMock->getWeights()->getValue(0));
        
        delete neuronMock;
    }

    /*
     * Tests whether the weights of a <code>BDN</code> are
     * initialized correctly.
     *
     */
    TEST_F(BDNTrainerTest, InitWeightsBDNTest) {
        EXPECT_CALL(*(bdnMock), getType())
                .WillOnce(Return(NEURON_TYPE_BDN));
        trainer->initWeights(bdnMock);
        Weights *w = bdnMock->getWeights();
        for (int i = 0; i < w->getSize(); i++) {
            EXPECT_EQ(1.0f, w->getValue(i));
        }
    }

    /*
     * Tests whether the threshold is set correctly.
     *
     */
    TEST_F(BDNTrainerTest, SetThresholdTest) {
        trainer->setThreshold(bdnMock);
        EXPECT_EQ(0.5f, bdnMock->getThreshold());
    }
}
