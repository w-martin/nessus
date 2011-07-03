/* 
 * File:   Architecture.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 13:15
 */

#include "nn-simulator/main/model/Architecture.h"
#include <stdlib.h>

Architecture::Architecture(int noLayers, auto_ptr<OutputFunction> function,
        auto_ptr<Trainer> trainer)
throw (IllegalArgumentException) {
    if (!function.get())
        throw IllegalArgumentException("Error. No function.");
    if(!trainer.get())
        throw IllegalArgumentException("Error. No trainer.");
    Architecture::maxLayers = noLayers;
    Architecture::function = function;
    Architecture::trainer = trainer;
}

Architecture::~Architecture() {
}

int Architecture::getMaxLayers() {
    return maxLayers;
}

OutputFunction *Architecture::getFunction() {
    return function.get();
}

Trainer *Architecture::getTrainer() {
    return trainer.get();
}
