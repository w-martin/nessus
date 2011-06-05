/* 
 * File:   Weight.cpp
 * Author: Will
 * 
 * Created on 04 June 2011, 16:14
 */

#include "Weight.h"
#include <time.h>
#include <stdlib.h>

Weight::Weight(int noInputs) {
    Weight::size = noInputs;
    Weight::multipliers = new float[noInputs];
    for (int i = 0; i < noInputs; i++) {
        Weight::multipliers[i] = 1;
    }
}

Weight::~Weight() {
}

float Weight::getMultiplier(int i) {
    return Weight::multipliers[i];
}

void Weight::setMultiplier(int i, float newMultiplier) {
    Weight::multipliers[i] = newMultiplier;
}

void Weight::init() {
    srand(time(NULL));
    for (int i = 0; i < Weight::size; i++) {
        int random = rand();
        Weight::multipliers[i] = random / ((float) (2 * RAND_MAX));
    }
}
