/* 
 * File:   SupervisedTrainer.h
 * Author: Will
 *
 * Created on 08 June 2011, 15:51
 */

#ifndef SUPERVISEDTRAINER_H
#define	SUPERVISEDTRAINER_H

#include "Trainer.h"

/**
 * Supervised trainer subclass, which trains a <code>Neuron</code>'s
 * <code>Weights</code> using supervised learning.
 * 
 */
class SupervisedTrainer : public Trainer {
public:
    /**
     * Adapts the <code>Weights</code> of the given <code>Neuron</code>.
     * 
     * @param n the <code>Neuron</code> whose <code>Weights</code> will 
     * be adapted.
     * @return <code>true</code> if the <code>Weights</code> were 
     * successfully adapted, <code>false</code> otherwise.
     * 
     */
    virtual bool adaptWeights(Neuron const * const n) const = 0;
};

#endif	/* SUPERVISEDTRAINER_H */

