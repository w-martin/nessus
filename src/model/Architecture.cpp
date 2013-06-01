/*
 * File:   Architecture.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 13:15
 */

#include "nessus/model/Architecture.h"
#include <stdlib.h>

Architecture::Architecture(int const noLayers,
                           unique_ptr<OutputFunction> function,
                           unique_ptr<Trainer> trainer,
                           char const * const neuronType)
throw (IllegalArgumentException) {
  if (!function.get())
    throw IllegalArgumentException("Error. No function.");
  if (!trainer.get())
    throw IllegalArgumentException("Error. No trainer.");
  Architecture::maxLayers = noLayers;
  Architecture::function = std::move(function);
  Architecture::trainer = std::move(trainer);
  Architecture::neuronType = neuronType;
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

char const * const Architecture::getNeuronType() const {
  return neuronType;
}
