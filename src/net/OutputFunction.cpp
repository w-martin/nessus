/* 
 * File:   OutputFunction.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 10:52
 */

#include "OutputFunction.h"
#include <math.h>

Output *OutputFunction::heavisideFunction(
        float activation, float threshold) {
    Output *output;
    if (activation > threshold)
        output = new Output(1);
    else
        output = new Output(0);
    return output;
}

Output *OutputFunction::sigmoidFunction(
        float activation) {
    float denominator = 1.0f + expf(-activation);
    float result = 1.0f / denominator;
    Output *output = new Output(result);
    return output;
}

Output *OutputFunction::sigmoidDerivativeFunction(
        float activation) {
    Output *fx = sigmoidFunction(activation);
    float result = fx->getValue() * (1.0f - fx->getValue());
    Output *output = new Output(result);
    return output;
}
