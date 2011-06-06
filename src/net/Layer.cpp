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
}

