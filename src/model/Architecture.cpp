/* 
 * File:   Architecture.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 13:15
 */

#include "Architecture.h"
#include <stdlib.h>

Architecture::Architecture(int noLayers) {
    Architecture::maxLayers = noLayers;
}

Architecture::~Architecture() {
    free(function);
    free(trainer);
}

int Architecture::getMaxLayers() {
    return Architecture::maxLayers;
}

void Architecture::setFunction(OutputFunction* newFunction) {
    function = newFunction;
}

OutputFunction *Architecture::getFunction() {
    return function;
}

void Architecture::setTrainer(Trainer* newTrainer) {
    Architecture::trainer = newTrainer;
}

Trainer *Architecture::getTrainer() {
    return Architecture::trainer;
}
