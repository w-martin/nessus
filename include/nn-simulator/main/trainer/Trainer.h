/* 
 * File:   Trainer.h
 * Author: Will
 *
 * Created on 08 June 2011, 09:28
 */

#ifndef TRAINER_H
#define	TRAINER_H

#include "nn-simulator/main/model/Neuron.h"

/**
 * Class which trains the <code>Weights</code> of a <code>Neuron</code>
 * in order to produce the desired output.
 * 
 */
class Trainer {
public:
    Trainer();
    virtual ~Trainer();
    /**
     * Initialises the <code>Weights</code> of the given 
     * <code>Neuron</code>.
     * 
     * @param n the <code>Neuron</code> to initialise the 
     * <code>Weights</code> for.
     * 
     */
    virtual void initWeights(Neuron const * const n) const;
protected:
    /**
     * Sets the <code>Weights</code> of the given <code>Neuron</code>
     * to small, random values.
     * 
     * @param n the <code>Neuron</code> to set the <code>Weights</code> 
     * for.
     * 
     */
    virtual void setRandomWeights(Neuron const * const n) const;
};

#endif	/* TRAINER_H */

