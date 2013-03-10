/*
 * File:   Layer.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 16:23
 */

#include <stdlib.h>

#include "nessus/model/Layer.h"

Layer::Layer(int const noNeurons, bool const adaptiveWeights) {
  size = noNeurons;
  Layer::adaptiveWeights = adaptiveWeights;
  neurons = new auto_ptr<Neuron>[size];
  for (int i = 0; i < noNeurons; i++) {
    neurons[i] = auto_ptr<Neuron > ();
  }
}

Layer::~Layer() {
}

int const Layer::getSize() const {
  return size;
}

void Layer::setNeuron(int const position, auto_ptr<Neuron> neuron) {
  neurons[position] = neuron;
}

Neuron * const Layer::getNeuron(int const position) const {
  if (neurons[position].get())
    return neurons[position].get();
  else
    return NULL;
}

bool const Layer::hasAdaptiveWeights() const {
  return adaptiveWeights;
}

Input const Layer::processInput(Input const &input) const {
  Input output(size);
  for (int i = 0; i < size; i++) {
    Output result = getNeuron(i)->processInput(input);
    output.setValue(i, result.getValue());
  }
  return output;
}
