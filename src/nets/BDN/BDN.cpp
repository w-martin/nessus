/*
 * File:   BDN.cpp
 * Author: Will
 *
 * Created on 08 June 2011, 11:00
 */

#include "nessus/nets/BDN/BDN.h"

BDN::BDN(int const &size,
         OutputFunction const * const f) :
  Neuron(size, f, NEURON_TYPE_BDN) {
  threshold = 0.0f;
}

const char * const BDN::getType() const {
  return NEURON_TYPE_BDN;
}

BDN::~BDN() {
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

void BDN::setExpectedInput(unique_ptr<Input> input) {
  expectedInput = std::move(input);
}

Input const * const BDN::getExpectedInput() const {
  return expectedInput.get();
}

void BDN::setNecessaryInput(unique_ptr<Input> input) {
  necessaryInput = std::move(input);
}

Input const * const BDN::getNecessaryInput() const {
  return necessaryInput.get();
}
