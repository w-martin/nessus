/* 
 * File:   Net.cpp
 * Author: Will
 * 
 * Created on 08 June 2011, 16:36
 */

#include <stdlib.h>

#include "Net.h"

Net::Net(Architecture *a, int noLayers, int noInputs)
throw (UnsupportedLayersException) {
    if (noLayers > a->getMaxLayers())
        throw new UnsupportedLayersException();

    size = noLayers;
    Net::noInputs = noInputs;
    layers = new Layer*[noLayers];
    for (int i = 0; i < noLayers; i++) {
        layers[i] = NULL;
    }
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
