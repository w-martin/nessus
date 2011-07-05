/* 
 * File:   Weights.h
 * Author: Will
 *
 * Created on 04 June 2011, 16:14
 */

#ifndef WEIGHTS_H
#define	WEIGHTS_H

#include "nn-simulator/main/model/exceptions/EmptyVectorException.h"
#include "nn-simulator/main/model/Vector.h"

/**
 * Weight Vector class for use with <code>Neuron</code>s.
 * 
 * @param noInputs the number of inputs the parent <code>Neuron</code>
 *  is expecting.
 * 
 */
class Weights : public Vector {
public:

    Weights(int const noInputs) throw (EmptyVectorException) : Vector(noInputs) {
    }

    Weights(const Weights &orig) throw (EmptyVectorException) : Vector(orig) {
    }

    virtual ~Weights() {
    }

    Weights &operator=(Weights const &other) {
        Weights(other.getSize());
        for (int i = 0; i < other.getSize(); i++) {
            setValue(i, other.getValue(i));
        }
        return *this;
    }
};

#endif	/* WEIGHTS_H */

