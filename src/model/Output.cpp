/* 
 * File:   Output.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 16:04
 */

#include "nn-simulator/main/model/Output.h"

Output::Output(float v) {
    Output::value = v;
}

Output::Output() {
    value = 0.0f;
}

Output::~Output() {
}

float Output::getValue() {
    return Output::value;
}