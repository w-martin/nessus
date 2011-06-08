/* 
 * File:   BDN.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 11:00
 */

#include "BDN.h"

BDN::BDN(Weights* w, OutputFunction* f) : Neuron(w, f) {
    Neuron(w, f);
    threshold = 0.0f;
}

BDN::~BDN() {
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