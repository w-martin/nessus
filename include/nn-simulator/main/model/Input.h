/* 
 * File:   Input.h
 * Author: Will
 *
 * Created on 05 June 2011, 12:43
 */

#ifndef INPUT_H
#define	INPUT_H

#include "nn-simulator/main/model/exceptions/EmptyVectorException.h"
#include "nn-simulator/main/model/Vector.h"

/**
 * Input object for neurons.
 * 
 */
class Input : public Vector {
public:

    Input(int noInputs) throw (EmptyVectorException) : Vector(noInputs) {
    }

    Input(const Input &orig) throw (EmptyVectorException) : Vector(orig) {
    }

    virtual ~Input() {
    }

    Input &operator=(const Input &other) {
        Input(other.getSize());
        for (int i = 0; i < other.getSize(); i++) {
            setValue(i, other.getValue(i));
        }
        return *this;
    }
};

#endif	/* INPUT_H */

