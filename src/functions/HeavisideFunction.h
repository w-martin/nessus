/* 
 * File:   HeavisideFunction.h
 * Author: Will
 *
 * Created on 07 June 2011, 14:08
 */

#ifndef HEAVISIDEFUNCTION_H
#define	HEAVISIDEFUNCTION_H

#include "OutputFunction.h"

/**
 * Computes the <code>Output</code> of a neuron using the given
 * activation and threshold by applying the <code>Heaviside</code>
 * function.
 * 
 */
class HeavisideFunction : public OutputFunction {
public:
    HeavisideFunction();
    virtual ~HeavisideFunction();
    Output *function(const float activation);
private:
};

#endif	/* HEAVISIDEFUNCTION_H */

