/* 
 * File:   Layer.cpp
 * Author: Will
 * 
 * Created on 06 June 2011, 16:23
 */

#include <stdlib.h>
#include <iostream>

#include "model/Layer.h"

Layer::Layer(int noNeurons, bool aw) {
    size = noNeurons;
    Layer::adaptiveWeights = aw;
    neurons = new Neuron*[noNeurons];
    for (int i = 0; i < noNeurons; i++) {
        neurons[i] = NULL;
    }
}

Layer::~Layer() {
    //    for (int i = 0; i < Layer::size; i++) {
    //        if (NULL != neurons[i]) {
    //            neurons[i]->~Neuron();
    //            delete neurons[i];
    //        }
    //    }
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
    std::cout << "here5\n";
    Input *output = new Input(size);
    for (int i = 0; i < size; i++) {
        std::cout << "here6\n";
        Output *result = getNeuron(i)->processInput(input);
        std::cout << "here7\n";
        output->setValue(i, result->getValue());
        std::cout << "here8\n";
    }
    return output;
}
