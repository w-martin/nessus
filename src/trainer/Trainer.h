/* 
 * File:   Trainer.h
 * Author: Will
 *
 * Created on 08 June 2011, 09:28
 */

#ifndef TRAINER_H
#define	TRAINER_H

#include "../model/Neuron.h"

/**
 * Class which trains the <code>Weights</code> of a <code>Neuron</code>
 * in order to produce the desired output.
 * 
 */
class Trainer {
public:

    Trainer() {
    }

    ~Trainer() {
    };
    /**
     * Adapts the <code>Weights</code> of the given <code>Neuron</code>.
     * 
     * @param n the <code>Neuron</code> whose <code>Weights</code> will 
     * be adapted.
     * @return <code>true</code> if the <code>Weights</code> were 
     * successfully adapted, <code>false</code> otherwise.
     * 
     */
    virtual bool adaptWeights(Neuron *n) = 0;
};

#endif	/* TRAINER_H */

