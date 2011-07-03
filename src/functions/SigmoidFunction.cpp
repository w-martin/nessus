/* 
 * File:   SigmoidFunction.cpp
 * Author: Will
 * 
 * Created on 07 June 2011, 14:21
 */

#include "nn-simulator/main/functions/SigmoidFunction.h"

SigmoidFunction::SigmoidFunction() {
}

SigmoidFunction::~SigmoidFunction() {
}

Output SigmoidFunction::function(
        float activation) {
    float denominator = 1.0f + expf(-activation);
    float result = 1.0f / denominator;
    return Output(result);
}

Output SigmoidFunction::derivative(
        float activation) {
    Output fx = function(activation);
    float result = fx.getValue() * (1.0f - fx.getValue());
    return Output(result);
}
