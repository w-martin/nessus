/* 
 * File:   BDNTrainer.h
 * Author: Will
 *
 * Created on 09 June 2011, 13:39
 */

#ifndef BDNTRAINER_H
#define	BDNTRAINER_H

#include "../../trainer/Trainer.h"
#include "BDN.h"

class BDNTrainer : public Trainer {
public:
    BDNTrainer();
    virtual ~BDNTrainer();
    virtual void initWeights(Neuron *n);
    /**
     * Sets the threshold on the given <code>BDN</code>.
     * 
     * @param n the <code>BDN</code> whose threshold is to be set.
     * 
     */
    void setThreshold(BDN *n);
private:
};

#endif	/* BDNTRAINER_H */

