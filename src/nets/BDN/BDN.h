/* 
 * File:   BDN.h
 * Author: Will
 *
 * Created on 08 June 2011, 11:00
 */

#ifndef BDN_H
#define	BDN_H

#include "../../model/Neuron.h"

/**
 * Binary decision neuron class.
 * 
 */
class BDN : public Neuron {
public:
    BDN(Weights *w, OutputFunction *f);
    virtual ~BDN();
    float getThreshold();
    void setThreshold(const float t);
protected:
    Output* calculateActivation(Input *input);
private:
    float threshold;
};

#endif	/* BDN_H */
