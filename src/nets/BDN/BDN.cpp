/* 
 * File:   BDN.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 11:00
 */

#include "nets/BDN/BDN.h"

BDN::BDN(Weights* w, OutputFunction* f) : Neuron(w, f) {
    Neuron(w, f);
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

Output *BDN::calculateActivation(Input* input) {
    float total = 0.0f;
    for (int i = 0; i < input->getSize(); i++) {
        total += input->getValue(i) * getWeights()->getMultiplier(i);
    }
    total -= threshold;
    Output *output = new Output(total);
    return output;
}

void BDN::setExpectedInput(Input* input) {
    BDN::expectedInput = input;
}

Input *BDN::getExpectedInput() {
    return expectedInput;
}

void BDN::setNecessaryInput(Input* input) {
    BDN::necessaryInput = input;
}

Input *BDN::getNecessaryInput() {
    return necessaryInput;
}
