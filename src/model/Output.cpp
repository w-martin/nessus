/* 
 * File:   Output.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 16:04
 */

#include "model/Output.h"

Output::Output(float v) {
    Output::value = v;
}

Output::~Output() {
}

float Output::getValue() {
    return Output::value;
}