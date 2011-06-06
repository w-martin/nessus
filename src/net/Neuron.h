/* 
 * File:   Neuron.h
 * Author: Will
 *
 * Created on 06 June 2011, 13:13
 */

#ifndef NEURON_H
#define	NEURON_H

#include "Weight.h"
#include "Input.h"

/**
 * Interface for neurons.
 * 
 */
class Neuron {
public:

    Neuron(Weight *weight) {
        Neuron::weight = weight;
    }
    virtual ~Neuron();

    /**
     * Processes the given <code>Input</code> to produce the 
     * <code>Neuron</code>'s <code>Output</code>.
     * 
     * @param input the <code>Input</code> to process.
     * @return the <code>Neuron</code>'s <code>Output</code>.
     * 
     */
    Output* processInput(Input *input) {
        Output* activation = calculateActivation(input);
        Output* result = applyOutputFunction(activation->getValue());
        return result;
    }
private:
    Weight *weight;

    /**
     * Calculates the <code>Neuron</code>'s activation from the
     * given <code>Input</code>.
     * 
     * @param input the <code>Input</code> to calculate the activation
     * for.
     * @return the <code>Neuron</code>'s activation from the
     * given <code>Input</code>.
     * 
     */
    Output* calculateActivation(Input *input) {
        float total = 0.0f;
        for (int i = 0; i < input->getSize(); i++) {
            total += input->getValue(i) * weight->getMultiplier(i);
        }
        Output *output = new Output(total);
        return output;
    }

    /**
     * Applies the <code>Neuron</code>'s elected output function
     * to the given activation.
     * 
     * @param activation the activation to apply the output function to.
     * @return the output from the <code>Neuron</code>'s elected 
     * output function on the given activation.
     * 
     */
    Output* applyOutputFunction(float activation);
};

#endif	/* NEURON_H */

