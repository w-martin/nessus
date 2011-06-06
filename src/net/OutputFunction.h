/* 
 * File:   OutputFunction.h
 * Author: Will
 *
 * Created on 05 June 2011, 12:46
 */

#ifndef OUTPUTFUNCTION_H
#define	OUTPUTFUNCTION_H

#include "Output.h"

/**
 * Output function interface.
 * 
 */
class OutputFunction {
public:
    /**
     * Computes the <code>Output</code> of a neuron using the given
     * activation and threshold by applying the <code>Heaviside</code>
     * function.
     * 
     * @param activation the activation of the neuron.
     * @param threshold the threshold of the neuron.
     * @return the <code>Output</code> of the neuron.
     * 
     */
    static Output heavisideFunction(float activation, float threshold);
    /**
     * Computes the <code>Output</code> of a neuron using the given
     * activation by applying the <code>Sigmoid</code> function.
     * 
     * @param activation the activation of the neuron.
     * @return the <code>Output</code> of the neuron.
     * 
     */
    static Output sigmoidFunction(float activation);
    /**
     * Computes the <code>Output</code> from the <code>Sigmoid</code>
     * derivative function, for use in the error back-propagation
     * training process.
     * 
     * @param activation the activation of the neuron.
     * @return the <code>Output</code> from the <code>Sigmoid</code>
     * derivative function.
     * 
     */
    static Output sigmoidDerivativeFunction(float activation);
private:
};

#endif	/* OUTPUTFUNCTION_H */

