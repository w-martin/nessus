/* 
 * File:   Net.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 16:36
 */

#include <stdlib.h>

#include "nessus/model/Net.h"

Net::Net(auto_ptr<Architecture> architecture,
        int const &noLayers,
        int const &noInputs,
        const char * const netType)
throw (UnsupportedConfigurationException, IllegalArgumentException) {
    if (!architecture.get())
        throw IllegalArgumentException("Architecture cannot be NULL.");
    if (architecture->getMaxLayers() > 0
            && noLayers > architecture->getMaxLayers())
        throw UnsupportedConfigurationException();

    Net::architecture = architecture;
    Net::noLayers = noLayers;
    Net::noInputs = noInputs;
    layers = new auto_ptr<Layer>[noLayers];
    Net::type = netType;
}

Net::~Net() {
    delete [] layers;
}

int const Net::getNoLayers() const {
    return noLayers;
}

const char * const Net::getNetType() const {
    return type;
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

int const Net::getNoInputs() const {
    return noInputs;
}

Output const Net::processInput(Input const &input) const
throw (IncorrectInputException) {
    if (input.getSize() != noInputs) {
        throw IncorrectInputException();
    }
    Input currentInput = input;
    for (int i = 0; i < noLayers; i++) {
        Input nextInput = getLayer(i)->processInput(currentInput);
        currentInput = nextInput;
    }
    Output result = Output(currentInput.getValue(0));
    return result;
}
