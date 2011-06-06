/* 
 * File:   Output.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 10:26
 */

#include "Output.h"

Output::Output(float value) {
    Output::value = value;
}

float Output::getValue() {
    return Output::value;
}