/* 
 * File:   Layer.cpp
 * Author: Will
 * 
 * Created on 06 June 2011, 16:23
 */

#include <stdlib.h>

#include "Layer.h"

Layer::Layer(int noNeurons, bool aw) {
    size = noNeurons;
    Layer::adaptiveWeights = aw;
    neurons = new Neuron*[noNeurons];
    for (int i = 0; i < noNeurons; i++) {
        neurons[i] = NULL;
    }
}

Layer::~Layer() {
    for (int i = 0; i < Layer::size; i++) {
        if (NULL != neurons[i])
            neurons[i]->~Neuron();
    }
    free(neurons);
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
