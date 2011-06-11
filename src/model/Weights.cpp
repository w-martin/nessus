/* 
 * File:   Weights.cpp
 * Author: Will
 * 
 * Created on 04 June 2011, 16:14
 */

#include "Weights.h"
#include <stdlib.h>
#include <iostream>

Weights::Weights(int noInputs) {
    Weights::size = noInputs;
    Weights::multipliers = new float[noInputs];
    for (int i = 0; i < noInputs; i++) {
        Weights::multipliers[i] = 1;
    }
}

Weights::~Weights() {
    //    free(multipliers);
}

float Weights::getMultiplier(int i) {
    return Weights::multipliers[i];
}

void Weights::setMultiplier(int i, float newMultiplier) {
    std::cout << "setting " << i << " to " << newMultiplier << "\n";
    Weights::multipliers[i] = newMultiplier;
}

int Weights::getSize() {
    return size;
}
