/* 
 * File:   Weights.cpp
 * Author: Will
 * 
 * Created on 04 June 2011, 16:14
 */

#include "Weights.h"
#include <time.h>
#include <stdlib.h>

Weights::Weights(int noInputs) {
    Weights::size = noInputs;
    Weights::multipliers = new float[noInputs];
    for (int i = 0; i < noInputs; i++) {
        Weights::multipliers[i] = 1;
    }
}

Weights::~Weights() {
    free(multipliers);
}

float Weights::getMultiplier(int i) {
    return Weights::multipliers[i];
}

void Weights::setMultiplier(int i, float newMultiplier) {
    Weights::multipliers[i] = newMultiplier;
}

void Weights::init() {
    srand(time(NULL));
    for (int i = 0; i < Weights::size; i++) {
        int random = rand();
        Weights::multipliers[i] = random / ((float) (2 * RAND_MAX));
    }
}
