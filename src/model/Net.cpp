/* 
 * File:   Net.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 16:36
 */

#include <stdlib.h>

#include "Net.h"
#include "exceptions/IncorrectInputException.h"
#include <iostream>

Net::Net(Architecture *a, int noLayers, int noInputs)
throw (UnsupportedLayersException) {
    if (a->getMaxLayers() > 0
            && noLayers > a->getMaxLayers())
        throw new UnsupportedLayersException();

    architecture = a;
    size = noLayers;
    Net::noInputs = noInputs;
    layers = new Layer*[noLayers];
    std::cout << "called super constructor" << '\n';
}

Net::~Net() {
    for (int i = 0; i < size; i++) {
        if (NULL != layers[i])
            layers[i]->~Layer();
    }
    free(layers);
    architecture->~Architecture();
    free(architecture);
}

int Net::getSize() {
    return size;
}

void Net::setLayer(int i, Layer* newLayer) {
    layers[i] = newLayer;
}

Layer *Net::getLayer(int i) {
    return layers[i];
}

Architecture *Net::getArchitecture() {
    return architecture;
}

void Net::setNoInputs(int noInputs) {
    Net::noInputs = noInputs;
}

int Net::getNoInputs() {
    return noInputs;
}

Output *Net::processInput(Input* input) throw (IncorrectInputException) {
    if (input->getSize() != noInputs) {
        throw new IncorrectInputException();
    }

    Input *nextInput = input;
    for (int i = 0; i < size; i++) {
        nextInput = getLayer(i)->processInput(nextInput);
    }
    Output *result = new Output(nextInput->getValue(0));
    return result;
}
