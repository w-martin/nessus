/* 
 * File:   Neuron.h
 * Author: Will
 *
 * Created on 06 June 2011, 13:13
 */

#ifndef NEURON_H
#define	NEURON_H

#include "Weights.h"
#include "Input.h"
#include "Output.h"
#include "../functions/OutputFunction.h"

/**
 * Interface for neurons.
 * 
 */
class Neuron {
public:
    Neuron(Weights *w, OutputFunction *f);
    virtual ~Neuron();
    /**
     * Processes the given <code>Input</code> to produce the 
     * <code>Neuron</code>'s <code>Output</code>.
     * 
     * @param input the <code>Input</code> to process.
     * @return the <code>Neuron</code>'s <code>Output</code>.
     * 
     */
    Output *processInput(Input *input);
    /**
     * Gets the expected <code>Output</code> for this 
     * <code>Neuron</code>.
     * 
     * @return the expected <code>Output</code> for this 
     * <code>Neuron</code>.
     * 
     */
    Output *getExpectedOutput();
    /**
     * Sets the expected <code>Output</code> for this 
     * <code>Neuron</code>.
     * 
     * @param newExpectedOutput the new expected <code>Output</code> 
     * for this <code>Neuron</code>.
     * 
     */
    void setExpectedOutput(Output *newExpectedOutput);
    /**
     * Gets the <code>Weights</code> for this <code>Neuron</code>.
     * 
     * @return the <code>Weights</code> for this <code>Neuron</code>.
     * 
     */
    Weights *getWeights();
protected:
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
    virtual Output* calculateActivation(Input *input);
private:
    Weights *weights;
    Output *expectedOutput;
    OutputFunction *function;
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

