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

    Weights(int noInputs) throw (EmptyVectorException*) : Vector(noInputs) {
    }

    Weights(Weights &orig) : Vector(orig) {
    }

    virtual ~Weights() {

    }
};

#endif	/* WEIGHTS_H */

