/* 
 * File:   Net.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 16:36
 */

#include <stdlib.h>

#include "nn-simulator/main/model/Net.h"

Net::Net(Architecture *a, int noLayers, int noInputs)
throw (UnsupportedConfigurationException*, IllegalArgumentException*) {
    if (NULL == a)
        throw new IllegalArgumentException("Architecture cannot be NULL.");
    if (a->getMaxLayers() > 0
            && noLayers > a->getMaxLayers())
        throw new UnsupportedConfigurationException();

    architecture = a;
    size = noLayers;
    Net::noInputs = noInputs;
    layers = new Layer*[noLayers];
}

Net::~Net() {
    for (int i = 0; i < size; i++) {
        if (NULL != layers[i])
            layers[i]->~Layer();
    }
    delete [] layers;
    architecture->~Architecture();
    delete architecture;
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

Output *Net::processInput(Input* input) throw (IncorrectInputException*) {
    if (input->getSize() != noInputs) {
        throw new IncorrectInputException();
    }
    Input *currentInput = input;
    for (int i = 0; i < size; i++) {
        Input *nextInput = getLayer(i)->processInput(currentInput);
        if (currentInput != input)
            currentInput->~Input();
        currentInput = nextInput;
    }
    Output *result = new Output(currentInput->getValue(0));
    return result;
}
