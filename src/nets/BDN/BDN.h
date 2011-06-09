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
    /**
     * Gets the value of the threshold of this <code>BDN</code>.
     * 
     * @return the value of the threshold of this <code>BDN</code>.
     * 
     */
    float getThreshold();
    /**
     * Sets the value of the threshold of this <code>BDN</code>.
     * 
     * @param t the value of the threshold of this <code>BDN</code>.
     * 
     */
    void setThreshold(const float threshold);
    /**
     * Sets the expected <code>Input</code> for this <code>BDN</code>.
     * 
     * @param input the expected <code>Input</code> for this <code>BDN</code>.
     * 
     */
    void setExpectedInput(Input *input);
    /**
     * Gets the expected <code>Input</code> for this <code>BDN</code>.
     * 
     * @return the expected <code>Input</code> for this <code>BDN</code>.
     * 
     */
    Input *getExpectedInput();
    /**
     * Sets the necessary <code>Input</code> for this <code>BDN</code>.
     * For example, the expected input will differ from the necessary
     * input when modelling logical OR functions.
     * 
     * @param input the necessary <code>Input</code> for this 
     * <code>BDN</code>.
     * 
     */
    void setNecessaryInput(Input *input);
    /**
     * Gets input the necessary <code>Input</code> for this 
     * <code>BDN</code>. 
     * For example, the expected input will differ from the necessary
     * input when modelling logical OR functions.
     * 
     * @return input the necessary <code>Input</code> for this 
     * <code>BDN</code>.
     * 
     */
    Input *getNecessaryInput();
protected:
    Output* calculateActivation(Input *input);
private:
    float threshold;
    Input *expectedInput;
    Input *necessaryInput;
};

#endif	/* BDN_H */
