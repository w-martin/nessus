/* 
 * File:   Vector.cpp
 * Author: will
 *
 * Created on June 19, 2011, 6:05 PM
 */

#include <string.h>
#include <sstream>
#include <math.h>

#include "nn-simulator/main/model/Vector.h"

using std::stringstream;

Vector::Vector(int noInputs) throw (EmptyVectorException) {
    if (0 == noInputs)
        throw EmptyVectorException();

    size = noInputs;
    multipliers = new float[noInputs];
    for (int i = 0; i < noInputs; i++) {
        multipliers[i] = 1;
    }
}

Vector::Vector(const Vector& orig) throw (EmptyVectorException) {
    size = orig.getSize();
    multipliers = new float[size];
    for (int i = 0; i < size; i++) {
        multipliers[i] = orig.getValue(i);
    }
}

Vector::~Vector() {
    delete [] multipliers;
}

Vector &Vector::operator =(const Vector& other) {
    Vector(other.getSize());
    for (int i = 0; i < other.getSize(); i++) {
        setValue(i, other.getValue(i));
    }
    return *this;
}

float Vector::getValue(int i) const throw (OutOfBoundsException) {
    if (i < size)
        return multipliers[i];
    else {
        stringstream message;
        message << "Getting out of bounds. Accessing " << i
                << " when size is " << size << ".";
        throw OutOfBoundsException(message.str().c_str());
    }
}

void Vector::setValue(int i, float newMultiplier)
throw (OutOfBoundsException) {
    if (i < size)
        multipliers[i] = newMultiplier;
    else {
        stringstream message;
        message << "Setting out of bounds. Accessing " << i
                << " when size is " << size << ".";
        throw OutOfBoundsException(message.str().c_str());
    }
}

int Vector::getSize() const {
    return size;
}
