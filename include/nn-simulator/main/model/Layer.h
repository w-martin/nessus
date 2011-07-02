/* 
 * File:   Layer.h
 * Author: Will
 *
 * Created on 06 June 2011, 16:23
 */

#ifndef LAYER_H
#define	LAYER_H

#include "Neuron.h"
#include <memory>

using std::auto_ptr;

/**
 * Layer object constitutes of a number of <code>Neuron</code>s.
 * Processes an <code>Input</code> by passing it to each 
 * <code>Neuron</code> to produce either a single <code>Output</code>
 * or an <code>Input</code> vector to be passed to another 
 * <code>Layer</code>.
 * 
 */
class Layer {
public:
    /**
     * Default constructor.
     * 
     * @param noNeurons the number of <code>Neuron</code>s in this
     * <code>Layer</code>.
     * @param adaptiveWeights boolean indicating whether this 
     * <code>Layer</code> has adaptive <code>Weights</code>.
     * 
     */
    Layer(int noNeurons, bool adaptiveWeights);
    virtual ~Layer();
    /**
     * Gets the number of <code>Neuron</code>s in this 
     * <code>Layer</code>.
     * 
     * @return the number of <code>Neuron</code>s in this 
     * <code>Layer</code>.
     * 
     */
    int getSize();
    /**
     * Sets the <code>Neuron</code> at the given position to be the
     * given <code>Neuron</code>.
     * 
     * @param position the position at which to set the 
     * <code>Neuron</code>.
     * @param neuron the <code>Neuron</code> to set.
     * 
     */
    void setNeuron(int position, auto_ptr<Neuron> neuron);
    /**
     * Gets the <code>Neuron</code> at the given position.
     * 
     * @param position the position at which to get the 
     * <code>Neuron</code>.
     * @return the <code>Neuron</code> at the given position.
     * 
     */
    Neuron *getNeuron(int position);
    /**
     * Checks whether this <code>Layer</code> has adaptive 
     * <code>Weights</code> or not.
     * 
     * @return <code>true</code> if this <code>Layer</code> has adaptive 
     * <code>Weights</code>, <code>false</code> otherwise.
     * 
     */
    bool hasAdaptiveWeights();
    /**
     * Processes the given <code>Input</code> to produce the another
     * <code>Input</code> vector as <code>Output</code>.
     * 
     * @param input the <code>Input</code> to process.
     * @return an <code>Input</code> vector which is represents the
     * <code>Output</code> of each constituent <code>Neuron</code>.
     * 
     */
    Input *processInput(Input *input);
private:
    int size;
    auto_ptr<Neuron> *neurons;
    bool adaptiveWeights;
};

#endif	/* LAYER_H */

