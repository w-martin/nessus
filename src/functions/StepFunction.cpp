/* 
 * File:   StepFunction.cpp
 * Author: Will
 * 
 * Created on 04 June 2011, 16:14
 */

#include "OutputFunction.h"

static Output OutputFunction::computeOutput(
        float activation, float threshold) {
    Output output;
    if (activation > threshold)
        output = new Output(1);
    else
        output = new Output(0);
    return output;
}