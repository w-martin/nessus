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

Output HeavisideFunction::function(
        float activation) {
    if (activation > 0)
        return Output(1);
    else
        return Output(0);
}
