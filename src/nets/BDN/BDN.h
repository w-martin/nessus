/* 
 * File:   BDN.h
 * Author: Will
 *
 * Created on 08 June 2011, 11:00
 */

#ifndef BDN_H
#define	BDN_H
#define NEURON_TYPE_BDN "binary decision neuron"

#include "../../model/Neuron.h"

/**
 * Binary decision neuron class.
 * 
 */
class BDN : public Neuron {
public:
    BDN(Weights *w, OutputFunction *f);
    virtual ~BDN();
    virtual const char *getType();
    float getThreshold();
    void setThreshold(const float t);
    void setExpectedInput(Input *input);
    Input *getExpectedInput();
protected:
    Output* calculateActivation(Input *input);
private:
    float threshold;
    Input *expectedInput;
};

#endif	/* BDN_H */
