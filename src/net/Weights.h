/* 
 * File:   Weights.h
 * Author: Will
 *
 * Created on 04 June 2011, 16:14
 */

#ifndef WEIGHTS_H
#define	WEIGHTS_H

#include <vector>

/**
 * Weight Vector class for use with <code>Neuron</code>s.
 * 
 * @param noInputs the number of inputs the parent <code>Neuron</code>
 *  is expecting.
 * 
 */
class Weights {
public:
    Weights(int noInputs);
    virtual ~Weights();
    /**
     * Gets the multiplier associated with the given input vector i.
     * 
     * @param i the input vector to get.
     * @return the multiplier associated with the given input vector i.
     * 
     */
    float getMultiplier(int i);
    /**
     * Sets the multiplier associated with the given input vector i
     * to the given value newMultiplier.
     * 
     * @param i the input vector to set.
     * @param newMultiplier the new multiplier for the given input
     * vector.
     * 
     */
    void setMultiplier(int i, float newMultiplier);
    /**
     * Initialises the multipliers to small, random values.
     * 
     */
    void init();
private:
    float *multipliers;
    int size;
};

#endif	/* WEIGHTS_H */

