/* 
 * File:   OutputFunction.h
 * Author: Will
 *
 * Created on 05 June 2011, 12:46
 */

#ifndef OUTPUTFUNCTION_H
#define	OUTPUTFUNCTION_H

#include "../net/Output.h"

/**
 * Output function interface.
 * 
 */
class OutputFunction {
public:
    /**
     * Computes the <code>Output</code> of a neuron using the given
     * activation and threshold.
     * 
     * @param activation the activation of the neuron.
     * @param threshold the threshold of the neuron.
     * @return the <code>Output</code> of a neuron.
     * 
     */
    static Output computeOutput(float activation, float threshold);
private:
};

#endif	/* OUTPUTFUNCTION_H */

