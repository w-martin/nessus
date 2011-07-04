/* 
 * File:   Layer.cpp
 * Author: Will
 * 
 * Created on 06 June 2011, 16:23
 */

#include <stdlib.h>

#include "nn-simulator/main/model/Layer.h"

Layer::Layer(int noNeurons, bool adaptiveWeights) {
    size = noNeurons;
    Layer::adaptiveWeights = adaptiveWeights;
    neurons = new auto_ptr<Neuron>[size];
    for (int i = 0; i < noNeurons; i++) {
        neurons[i] = auto_ptr<Neuron > ();
    }
}

Layer::~Layer() {
}

int Layer::getSize() {
    return size;
}

void Layer::setNeuron(int position, auto_ptr<Neuron> neuron) {
    neurons[position] = neuron;
}

Neuron *Layer::getNeuron(int position) {
    if (neurons[position].get())
        return neurons[position].get();
    else
        return NULL;
}

bool Layer::hasAdaptiveWeights() {
    return adaptiveWeights;
}

Input Layer::processInput(Input input) {
    Input output(size);
    for (int i = 0; i < size; i++) {
        Output result = getNeuron(i)->processInput(input);
        output.setValue(i, result.getValue());
    }
    return output;
}
