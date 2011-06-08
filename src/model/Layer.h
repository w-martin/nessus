/* 
 * File:   Layer.h
 * Author: Will
 *
 * Created on 06 June 2011, 16:23
 */

#ifndef LAYER_H
#define	LAYER_H

#include "Neuron.h"

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
    Layer(int noNeurons);
    virtual ~Layer();
    /**
     * Sets the <code>Neuron</code> at the given position to be the
     * given <code>Neuron</code>.
     * 
     * @param position the position at which to set the 
     * <code>Neuron</code>.
     * @param neuron the <code>Neuron</code> to set.
     * 
     */
    void setNeuron(int position, Neuron *neuron);
    /**
     * Gets the <code>Neuron</code> at the given position.
     * 
     * @param position the position at which to get the 
     * <code>Neuron</code>.
     * @return the <code>Neuron</code> at the given position.
     * 
     */
    Neuron *getNeuron(int position);
private:
    int size;
    Neuron **neurons;
};

#endif	/* LAYER_H */

