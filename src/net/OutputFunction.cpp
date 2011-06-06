/* 
 * File:   OutputFunction.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 10:52
 */

#include "OutputFunction.h"
#include <math.h>

static Output OutputFunction::heavisideFunction(
        float activation, float threshold) {
    Output output;
    if (activation > threshold)
        output = new Output(1);
    else
        output = new Output(0);
    return output;
}

static Output OutputFunction::sigmoidFunction(
        float activation) {
    float denom = 1.0f + expf(-activation);
    float result = 1.0f / denom;
    return new Output(result);
}

static Output OutputFunction::sigmoidDerivativeFunction(
        float activation) {
    Output fx = sigmoidFunction(activation);
    float result = fx * (1.0f - fx);
    return new Output(result);
}