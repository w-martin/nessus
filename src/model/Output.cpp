/* 
 * File:   Output.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 16:04
 */

#include "nn-simulator/main/model/Output.h"

Output::Output(float const value) {
    Output::value = value;
}

Output::Output(const Output& orig) {
    value = orig.getValue();
}

Output::~Output() {
}

float const Output::getValue() const {
    return value;
}