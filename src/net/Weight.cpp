/* 
 * File:   Weight.cpp
 * Author: Will
 * 
 * Created on 04 June 2011, 16:14
 */

#include "Weight.h"

Weight::Weight(int noInputs) {
    Weight::multipliers = new double[noInputs];
    for (int i = 0; i < noInputs; i++) {
        Weight::multipliers[i] = 1;
    }
}

Weight::~Weight() {
}

double Weight::getMultiplier(int i) {
    return Weight::multipliers[i];
}
