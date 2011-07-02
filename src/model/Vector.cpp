/* 
 * File:   Vector.cpp
 * Author: will
 *
 * Created on June 19, 2011, 6:05 PM
 */

#include "nn-simulator/main/model/Vector.h"

Vector::Vector(int noInputs) throw (EmptyVectorException*) {
    if (0 == noInputs)
        throw new EmptyVectorException();

    size = noInputs;
    multipliers = new float[noInputs];
    for (int i = 0; i < noInputs; i++) {
        multipliers[i] = 1;
    }
}

Vector::~Vector() {
    delete [] multipliers;
}

float Vector::getValue(int i) throw (OutOfBoundsException*) {
    if (i < size)
        return multipliers[i];
    else throw new OutOfBoundsException();
}

void Vector::setValue(int i, float newMultiplier)
throw (OutOfBoundsException*) {
    if (i < size)
        multipliers[i] = newMultiplier;
    else throw new OutOfBoundsException();
}

int Vector::getSize() {
    return size;
}


