/* 
 * File:   Layer.cpp
 * Author: Will
 * 
 * Created on 06 June 2011, 16:23
 */

#include <stdlib.h>

#include "nn-simulator/main/model/Layer.h"

Layer::Layer(int noNeurons, bool aw) {
    size = noNeurons;
    Layer::adaptiveWeights = aw;
    neurons = new Neuron*[noNeurons];
    for (int i = 0; i < noNeurons; i++) {
        neurons[i] = NULL;
    }
}

Layer::~Layer() {
    delete [] neurons;
}

void Layer::setNeuron(int position, Neuron * neuron) {
    neurons[position] = neuron;
}

Neuron * Layer::getNeuron(int position) {
    return Layer::neurons[position];
}

bool Layer::hasAdaptiveWeights() {
    return adaptiveWeights;
}

Input *Layer::processInput(Input* input) {
    Input *output = new Input(size);
    for (int i = 0; i < size; i++) {
        Output *result = getNeuron(i)->processInput(input);
        output->setValue(i, result->getValue());
    }
    return output;
}
