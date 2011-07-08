/* 
 * File:   TrainerTest.cpp
 * Author: will
 * 
 * Created on 8th July 2011, 23:31
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/trainer/Trainer.h"
#include "nn-simulator/test/model/MockNeuron.h"

namespace {

    class TrainerTest : public ::testing::Test {
    protected:

        TrainerTest() {
            trainer = new Trainer();
        }

        virtual ~TrainerTest() {
            delete trainer;
        }
        Trainer *trainer;
    };

    /*
     * Tests whether the getValue method returns the correct
     * value.
     * 
     */
    TEST_F(TrainerTest, InitWeightsTest) {
        MockNeuron *neuronMock = new MockNeuron();
        trainer->initWeights((*neuronMock));
        
        Weights *weights = neuronMock->getWeights();
        for (int i = 0; i < weights->getSize(); i++) {
            EXPECT_LT(weights->getValue(i), 1.0f);
            EXPECT_GT(weights->getValue(i), 0.0f);
        }
    }
}
