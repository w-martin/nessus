/* 
 * File:   Neuron.h
 * Author: Will
 *
 * Created on 06 June 2011, 13:13
 */
#ifndef NEURON_H
#define	NEURON_H
#define NEURON_TYPE_STD "standard neuron"

#include "nn-simulator/main/model/Weights.h"
#include "nn-simulator/main/model/Input.h"
#include "nn-simulator/main/model/Output.h"
#include "nn-simulator/main/functions/OutputFunction.h"
#include "nn-simulator/main/util/exceptions/IllegalArgumentException.h"
#include <string.h>
#include <memory>

using std::auto_ptr;

/**
 * Interface for neurons.
 * 
 */
class Neuron {
public:
    Neuron(auto_ptr<Weights> weights, OutputFunction *f)
    throw (IllegalArgumentException*);
    virtual ~Neuron();
    /**
     * Gets the type of this <code>Neuron</code>.
     * 
     * @return the type of this <code>Neuron</code>.
     * 
     */
    virtual const char *getType();
    /**
     * Processes the given <code>Input</code> to produce the 
     * <code>Neuron</code>'s <code>Output</code>.
     * 
     * @param input the <code>Input</code> to process.
     * @return the <code>Neuron</code>'s <code>Output</code>.
     * @throw IllegalArgumentException if the input is null.
     * 
     */
    virtual Output *processInput(Input *input)
    throw (IllegalArgumentException*);
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
    void setExpectedOutput(auto_ptr<Output> newExpectedOutput)
    throw (IllegalArgumentException*);
    /**
     * Gets the <code>Weights</code> for this <code>Neuron</code>.
     * 
     * @return the <code>Weights</code> for this <code>Neuron</code>.
     * 
     */
    Weights *getWeights();
    /**
     * Gets the <code>OutputFunction</code> used by this 
     * <code>Neuron</code>.
     * 
     * @return the <code>OutputFunction</code> used by this 
     * <code>Neuron</code>.
     * 
     */
    OutputFunction *getOutputFunction();
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
    auto_ptr<Weights> weights;
    auto_ptr<Output> expectedOutput;
    OutputFunction *outputFunction;
    /**
     * Applies the <code>Neuron</code>'s elected output function
     * to the given activation.
     * 
     * @param activation the activation to apply the output function to.
     * @return the output from the <code>Neuron</code>'s elected 
     * output function on the given activation.
     * 
     */
    Output *applyOutputFunction(float activation);
};

#endif	/* NEURON_H */

