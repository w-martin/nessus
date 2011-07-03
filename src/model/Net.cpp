/* 
 * File:   Net.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 16:36
 */

#include <stdlib.h>

#include "nn-simulator/main/model/Net.h"

Net::Net(auto_ptr<Architecture> architecture, int noLayers, int noInputs)
throw (UnsupportedConfigurationException, IllegalArgumentException) {
    if (!architecture.get())
        throw IllegalArgumentException("Architecture cannot be NULL.");
    if (architecture->getMaxLayers() > 0
            && noLayers > architecture->getMaxLayers())
        throw UnsupportedConfigurationException();

    Net::architecture = architecture;
    size = noLayers;
    Net::noInputs = noInputs;
    layers = new Layer*[noLayers];
}

Net::~Net() {
    delete [] layers;
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
    return architecture.get();
}

void Net::setNoInputs(int noInputs) {
    Net::noInputs = noInputs;
}

int Net::getNoInputs() {
    return noInputs;
}

Output *Net::processInput(Input* input) throw (IncorrectInputException) {
    if (input->getSize() != noInputs) {
        throw IncorrectInputException();
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
