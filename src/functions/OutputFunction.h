/* 
 * File:   OutputFunction.h
 * Author: Will
 *
 * Created on 05 June 2011, 12:46
 */

#ifndef OUTPUTFUNCTION_H
#define	OUTPUTFUNCTION_H

#include "../model/Output.h"

/**
 * Output function interface.
 * 
 */
class OutputFunction {
public:

    OutputFunction() {
    }

    ~OutputFunction() {
    }
    /**
     * Applies the output function to the given activation.
     * 
     * @param activation the activation of a <code>Neuron</code>.
     * @return the result of the output function on the given
     * activation.
     * 
     */
    virtual Output *function(const float activation) = 0;
private:
};

#endif	/* OUTPUTFUNCTION_H */
