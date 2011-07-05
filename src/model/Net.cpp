/* 
 * File:   Net.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 16:36
 */

#include <stdlib.h>

#include "nn-simulator/main/model/Net.h"

Net::Net(auto_ptr<Architecture> architecture,
        int const noLayers,
        int const noInputs)
throw (UnsupportedConfigurationException, IllegalArgumentException) {
    if (!architecture.get())
        throw IllegalArgumentException("Architecture cannot be NULL.");
    if (architecture->getMaxLayers() > 0
            && noLayers > architecture->getMaxLayers())
        throw UnsupportedConfigurationException();

    Net::architecture = architecture;
    size = noLayers;
    Net::noInputs = noInputs;
    layers = new auto_ptr<Layer>[noLayers];
}

Net::~Net() {
    delete [] layers;
}

int const Net::getSize() const {
    return size;
}

void Net::setLayer(int const i, auto_ptr<Layer> newLayer) {
    layers[i] = newLayer;
}

Layer * const Net::getLayer(int const i) const {
    return layers[i].get();
}

Architecture const * const Net::getArchitecture() const {
    return architecture.get();
}

void Net::setNoInputs(int const noInputs) {
    Net::noInputs = noInputs;
}

int const Net::getNoInputs() const {
    return noInputs;
}

Output const Net::processInput(Input const &input) const
throw (IncorrectInputException) {
    if (input.getSize() != noInputs) {
        throw IncorrectInputException();
    }
    Input currentInput = input;
    for (int i = 0; i < size; i++) {
        Input nextInput = getLayer(i)->processInput(currentInput);
        currentInput = nextInput;
    }
    Output result = Output(currentInput.getValue(0));
    return result;
}
