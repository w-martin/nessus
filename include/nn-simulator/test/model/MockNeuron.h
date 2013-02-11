/* 
 * File:   MockNeuron.cpp
 * Author: Will
 * 
 * Created on 02 July, 18:12
 */

#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/test/model/MockWeights.h"
#include "nn-simulator/test/functions/MockOutputFunction.h"

#define NEURON_TYPE_MOCK "mock neuron type"

class MockNeuron : public Neuron {
public:

    MockNeuron() : Neuron(1, new MockOutputFunction(),
    NEURON_TYPE_MOCK) {
    }
};
