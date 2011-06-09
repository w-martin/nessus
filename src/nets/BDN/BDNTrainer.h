/* 
 * File:   BDNTrainer.h
 * Author: Will
 *
 * Created on 09 June 2011, 13:39
 */

#ifndef BDNTRAINER_H
#define	BDNTRAINER_H

#include "../../trainer/Trainer.h"

class BDNTrainer : public Trainer {
public:
    BDNTrainer();
    virtual ~BDNTrainer();
    virtual void initWeights(Neuron *n);
private:

};

#endif	/* BDNTRAINER_H */

