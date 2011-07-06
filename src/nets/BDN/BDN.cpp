/* 
 * File:   BDN.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 11:00
 */

#include "nn-simulator/main/nets/BDN/BDN.h"

BDN::BDN(auto_ptr<Weights> weights, 
        OutputFunction const * const f) : Neuron(weights, f) {
    threshold = 0.0f;
}

BDN::~BDN() {
}

const char * BDN::getType() const {
    return NEURON_TYPE_BDN;
}

float const BDN::getThreshold() const {
    return threshold;
}

void BDN::setThreshold(const float t) {
    BDN::threshold = t;
}

Output const BDN::calculateActivation(Input const &input) const {
    float total = 0.0f;
    for (int i = 0; i < input.getSize(); i++) {
        total += input.getValue(i) * getWeights()->getValue(i);
    }
    total -= threshold;
    Output output = Output(total);
    return output;
}

void BDN::setExpectedInput(auto_ptr<Input> input) {
    expectedInput = input;
}

Input const * const BDN::getExpectedInput() const {
    return expectedInput.get();
}

void BDN::setNecessaryInput(auto_ptr<Input> input) {
    necessaryInput = input;
}

Input const * const BDN::getNecessaryInput() const {
    return necessaryInput.get();
}
