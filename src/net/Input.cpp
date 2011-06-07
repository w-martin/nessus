/* 
 * File:   Input.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 13:21
 */

#include "Input.h"
#include <stdlib.h>

Input::Input(int noInputs) {
    Input::size = noInputs;
    Input::values = new float[noInputs];
    for (int i = 0; i < noInputs; i++) {
        Input::values[i] = 0;
    }
}

Input::~Input() {
    free(values);
}

float Input::getValue(int i) {
    return Input::values[i];
}

void Input::setValue(int i, float newInput) {
    Input::values[i] = newInput;
}

int Input::getSize() {
    return Input::size;
}