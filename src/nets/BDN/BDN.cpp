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

const char *BDN::getType() {
    return NEURON_TYPE_BDN;
}

float BDN::getThreshold() {
    return threshold;
}

void BDN::setThreshold(const float t) {
    BDN::threshold = t;
}

Output BDN::calculateActivation(Input input) {
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

Input *BDN::getExpectedInput() {
    return expectedInput.get();
}

void BDN::setNecessaryInput(auto_ptr<Input> input) {
    necessaryInput = input;
}

Input *BDN::getNecessaryInput() {
    return necessaryInput.get();
}
