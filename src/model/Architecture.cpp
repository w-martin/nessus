/* 
 * File:   Architecture.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 13:15
 */

#include "nn-simulator/main/model/Architecture.h"
#include <stdlib.h>

Architecture::Architecture(int noLayers,
        OutputFunction *function, Trainer *trainer)
throw (IllegalArgumentException*) {
    if (NULL == function
            || NULL == trainer)
        throw new IllegalArgumentException();
    Architecture::maxLayers = noLayers;
    Architecture::function = function;
    Architecture::trainer = trainer;
}

Architecture::~Architecture() {
    delete function;
    delete trainer;
}

int Architecture::getMaxLayers() {
    return Architecture::maxLayers;
}

OutputFunction *Architecture::getFunction() {
    return function;
}

Trainer *Architecture::getTrainer() {
    return Architecture::trainer;
}
