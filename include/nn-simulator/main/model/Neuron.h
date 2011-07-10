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
    Neuron(int const &size, OutputFunction const * const f)
    throw (IllegalArgumentException);
    virtual ~Neuron();
    /**
     * Gets the type of this <code>Neuron</code>.
     * 
     * @return the type of this <code>Neuron</code>.
     * 
     */
    virtual const char *getType() const;
    /**
     * Processes the given <code>Input</code> to produce the 
     * <code>Neuron</code>'s <code>Output</code>.
     * 
     * @param input the <code>Input</code> to process.
     * @return the <code>Neuron</code>'s <code>Output</code>.
     * 
     */
    virtual Output const processInput(Input const &input) const;
    /**
     * Gets the expected <code>Output</code> for this 
     * <code>Neuron</code>.
     * 
     * @return the expected <code>Output</code> for this 
     * <code>Neuron</code>.
     * 
     */
    Output const * const getExpectedOutput() const;
    /**
     * Sets the expected <code>Output</code> for this 
     * <code>Neuron</code>.
     * 
     * @param newExpectedOutput the new expected <code>Output</code> 
     * for this <code>Neuron</code>.
     * 
     */
    void setExpectedOutput(auto_ptr<Output> newExpectedOutput)
    throw (IllegalArgumentException);
    /**
     * Gets the <code>Weights</code> for this <code>Neuron</code>.
     * 
     * @return the <code>Weights</code> for this <code>Neuron</code>.
     * 
     */
    Weights * const getWeights() const;
    /**
     * Gets the <code>OutputFunction</code> used by this 
     * <code>Neuron</code>.
     * 
     * @return the <code>OutputFunction</code> used by this 
     * <code>Neuron</code>.
     * 
     */
    OutputFunction const * const getOutputFunction() const;
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
    virtual Output const calculateActivation(Input const &input) const;
private:
    Weights *weights;
    auto_ptr<Output> expectedOutput;
    OutputFunction const *outputFunction;
    /**
     * Applies the <code>Neuron</code>'s elected output function
     * to the given activation.
     * 
     * @param activation the activation to apply the output function to.
     * @return the output from the <code>Neuron</code>'s elected 
     * output function on the given activation.
     * 
     */
    Output const applyOutputFunction(float const activation) const;
};

#endif	/* NEURON_H */

