/*
 * File:   MockNeuron.cpp
 * Author: Will
 *
 * Created on 02 July, 18:12
 */

#include "nessus/model/Neuron.h"
#include "nessus/model/MockWeights.h"
#include "nessus/functions/MockOutputFunction.h"

#define NEURON_TYPE_MOCK "mock neuron type"

class MockNeuron : public Neuron {
public:

  MockNeuron() : Neuron(1, new MockOutputFunction(),
                          NEURON_TYPE_MOCK) {
  }
};
