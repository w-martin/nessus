/* 
 * File:   Input.h
 * Author: Will
 *
 * Created on 05 June 2011, 12:43
 */

#ifndef INPUT_H
#define	INPUT_H

#include "model/exceptions/EmptyVectorException.h"
#include "model/Vector.h"

/**
 * Input object for neurons.
 * 
 */
class Input : public Vector {
public:

    Input(int noInputs) throw (EmptyVectorException*) : Vector(noInputs) {
    }

    virtual ~Input() {

    }
};

#endif	/* INPUT_H */

