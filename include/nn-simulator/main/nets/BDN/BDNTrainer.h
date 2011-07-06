/* 
 * File:   BDNTrainer.h
 * Author: Will
 *
 * Created on 09 June 2011, 13:39
 */

#ifndef BDNTRAINER_H
#define	BDNTRAINER_H

#include "nn-simulator/main/trainer/Trainer.h"
#include "BDN.h"

class BDNTrainer : public Trainer {
public:
    BDNTrainer();
    virtual ~BDNTrainer();
    /**
     * Initializes the weights of the given <code>Neuron</code>.
     * 
     * @param n the <code>Neuron</code> to initialize the weights of.
     * 
     */
    virtual void initWeights(Neuron * const n) const;
    /**
     * Sets the threshold on the given <code>BDN</code>.
     * 
     * @param n the <code>BDN</code> whose threshold is to be set.
     * 
     */
    void setThreshold(BDN * const n) const;
};

#endif	/* BDNTRAINER_H */

