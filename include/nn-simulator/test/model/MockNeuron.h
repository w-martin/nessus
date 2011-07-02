/* 
 * File:   MockNeuron.cpp
 * Author: Will
 * 
 * Created on 02 July, 18:12
 */

#include "gmock/gmock.h"
#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/test/model/MockWeights.h"
#include "nn-simulator/test/functions/MockOutputFunction.h"

class MockNeuron : public Neuron {
public:

    MockNeuron() : Neuron(auto_ptr<Weights>(new MockWeights()),
    new MockOutputFunction()) {
    }

    MOCK_METHOD0(getType,
            const char*());
    MOCK_METHOD1(calculateActivation,
            Output*(Input *input));
};
