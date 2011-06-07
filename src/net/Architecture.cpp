/* 
 * File:   Architecture.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 13:15
 */

#include "Architecture.h"
#include <stdlib.h>

Architecture::Architecture(int noLayers) {
    Architecture::size = noLayers;
    Architecture::layers = new Layer*[noLayers];
    for (int i = 0; i < noLayers; i++) {
        layers[i] = NULL;
    }
}

Architecture::~Architecture() {
    for (int i = 0; i < size; i++) {
        if (NULL != layers[i])
            layers[i]->~Layer();
    }
    free(layers);
}

