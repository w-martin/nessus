/* 
 * File:   HeavisideFunction.cpp
 * Author: Will
 * 
 * Created on 07 June 2011, 14:08
 */

#include "nn-simulator/main/functions/HeavisideFunction.h"

HeavisideFunction::HeavisideFunction() {
}

HeavisideFunction::~HeavisideFunction() {
}

Output *HeavisideFunction::function(
        float activation) {
    Output *output;
    if (activation > 0)
        output = new Output(1);
    else
        output = new Output(0);
    return output;
}
