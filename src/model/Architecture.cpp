/* 
 * File:   Architecture.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 13:15
 */

#include "nn-simulator/main/model/Architecture.h"
#include <stdlib.h>

Architecture::Architecture(int const noLayers, 
        auto_ptr<OutputFunction> function,
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

int const Architecture::getMaxLayers() const {
    return maxLayers;
}

OutputFunction const * const Architecture::getFunction() const {
    return function.get();
}

Trainer const * const Architecture::getTrainer() const {
    return trainer.get();
}
