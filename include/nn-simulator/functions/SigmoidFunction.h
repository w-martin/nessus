/* 
 * File:   SigmoidFunction.h
 * Author: Will
 *
 * Created on 07 June 2011, 14:21
 */

#ifndef SIGMOIDFUNCTION_H
#define	SIGMOIDFUNCTION_H

#include "OutputFunction.h"

#include <math.h>

/**
 * Computes the <code>Output</code> of a neuron using the given
 * activation by applying the <code>Sigmoid</code> function.
 * 
 */
class SigmoidFunction : public OutputFunction {
public:
    SigmoidFunction();
    virtual ~SigmoidFunction();
    virtual Output *function(float activation);
    /**
     * Computes the <code>Output</code> from the <code>Sigmoid</code>
     * derivative function, for use in the error back - propagation
     * training process.
     *
     * @param activation the activation of the neuron.
     * @return the <code>Output</code> from the <code>Sigmoid</code>
     * derivative function.
     *
     */
    Output *derivative(float activation);
private:
};

#endif	/* SIGMOIDFUNCTION_H */

