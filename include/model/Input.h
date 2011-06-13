/* 
 * File:   Input.h
 * Author: Will
 *
 * Created on 05 June 2011, 12:43
 */

#ifndef INPUT_H
#define	INPUT_H

#include "model/exceptions/OutOfBoundsException.h"
#include "model/exceptions/EmptyInputException.h"

/**
 * Input object for neurons.
 * 
 */
class Input {
public:
    Input(int noInputs) throw (EmptyInputException);
    virtual ~Input();
    /**
     * Gets the input value at position i.
     * 
     * @param i the position to get the input value for.
     * @return the input value at position i.
     * 
     */
    float getValue(int i);
    /**
     * Sets the input value at position i.
     * 
     * @param i the position to set the input value for.
     * @param newInput the new input value.
     * @throw OutOfBoundsException if the position i is out of bounds of
     * this <code>Input</code> vector.
     * 
     */
    void setValue(int i, float newInput) throw (OutOfBoundsException);
    /**
     * Gets the size of the input.
     * 
     * @return the size of the input.
     * 
     */
    int getSize();
private:
    float *values;
    int size;
};

#endif	/* INPUT_H */

