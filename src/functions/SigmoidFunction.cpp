/* 
 * File:   SigmoidFunction.cpp
 * Author: Will
 * 
 * Created on 07 June 2011, 14:21
 */

#include "functions/SigmoidFunction.h"

SigmoidFunction::SigmoidFunction() {
}

SigmoidFunction::~SigmoidFunction() {
}

Output *SigmoidFunction::function(
        float activation) {
    float denominator = 1.0f + expf(-activation);
    float result = 1.0f / denominator;
    Output *output = new Output(result);
    return output;
}

Output *SigmoidFunction::derivative(
        float activation) {
    Output *fx = function(activation);
    float result = fx->getValue() * (1.0f - fx->getValue());
    Output *output = new Output(result);
    return output;
}