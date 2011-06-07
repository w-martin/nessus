/* 
 * File:   Layer.cpp
 * Author: Will
 * 
 * Created on 06 June 2011, 16:23
 */

#include <stdlib.h>

#include "Layer.h"

Layer::Layer(int noNeurons) {
    size = noNeurons;
    neurons = new Neuron*[noNeurons];
}

Layer::~Layer() {
    for (int i = 0; i < Layer::size; i++) {
        neurons[i]->~Neuron();
    }
}

void Layer::setNeuron(int position, Neuron* neuron) {
    neurons[position] = neuron;
}

Neuron *Layer::getNeuron(int position) {
    return Layer::neurons[position];
}