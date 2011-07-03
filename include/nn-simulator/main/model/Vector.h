/* 
 * File:   Vector.h
 * Author: will
 *
 * Created on June 19, 2011, 6:05 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include "nn-simulator/main/model/exceptions/EmptyVectorException.h"
#include "nn-simulator/main/util/exceptions/OutOfBoundsException.h"

/**
 * Vector superclass, for storing and retrieving a set of floats.
 * 
 */
class Vector {
public:
    Vector(int noInputs) throw (EmptyVectorException);
    Vector(Vector &orig);
    virtual ~Vector();
    /**
     * Gets the value associated with the given position i.
     * 
     * @param i the input vector to get.
     * @return the multiplier associated with the given input vector i.
     * @throw OutOfBoundsException if the given position i was out of
     * bounds.
     * 
     */
    float getValue(int i) throw (OutOfBoundsException);
    /**
     * Sets the value associated with the given position i
     * to the given value newValue.
     * 
     * @param i the input vector to set.
     * @param newValue the new value for the given position.
     * @throw OutOfBoundsException if the given position i was out of
     * bounds.
     * 
     */
    void setValue(int i, float newValue)
    throw (OutOfBoundsException);
    /**
     * Gets the size of this <code>Vector</code>.
     * 
     * @return the size of this <code>Vector</code>.
     * 
     */
    int getSize();
private:
    float *multipliers;
    int size;
};

#endif	/* VECTOR_H */

