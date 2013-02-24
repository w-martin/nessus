/* 
 * File:   Vector.h
 * Author: will
 *
 * Created on June 19, 2011, 6:05 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include "nessus/model/exceptions/EmptyVectorException.h"
#include "nessus/util/exceptions/OutOfBoundsException.h"

/**
 * Vector superclass, for storing and retrieving a set of floats.
 * 
 */
class Vector {
public:
    Vector(int const noInputs) throw (EmptyVectorException);
    Vector(const Vector &orig) throw (EmptyVectorException);
    virtual ~Vector();
    Vector &operator=(const Vector &other);
    /**
     * Gets the value associated with the given position i.
     * 
     * @param i the input vector to get.
     * @return the multiplier associated with the given input vector i.
     * @throw OutOfBoundsException if the given position i was out of
     * bounds.
     * 
     */
    float getValue(int const i) const throw (OutOfBoundsException);
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
    void setValue(int const i, const float newValue)
    throw (OutOfBoundsException);
    /**
     * Gets the size of this <code>Vector</code>.
     * 
     * @return the size of this <code>Vector</code>.
     * 
     */
    int const getSize() const;
private:
    float *multipliers;
    int size;
};

#endif	/* VECTOR_H */

