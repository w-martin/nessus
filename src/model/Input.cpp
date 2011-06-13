/* 
 * File:   Input.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 13:21
 */

#include "model/Input.h"
#include <stdlib.h>

Input::Input(int noInputs) throw (EmptyInputException) {
    if (noInputs == 0)
        throw new EmptyInputException();
    size = noInputs;
    values = new float[noInputs];
    for (int i = 0; i < noInputs; i++) {
        values[i] = 0.0f;
    }
}

Input::~Input() {
    delete [] values;
}

float Input::getValue(int i) {
    return Input::values[i];
}

void Input::setValue(int i, float newInput) throw (OutOfBoundsException) {
    if (i < size)
        Input::values[i] = newInput;
    else
        throw new OutOfBoundsException();
}

int Input::getSize() {
    return Input::size;
}