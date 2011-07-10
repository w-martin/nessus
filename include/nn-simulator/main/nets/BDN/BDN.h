/* 
 * File:   BDN.h
 * Author: Will
 *
 * Created on 08 June 2011, 11:00
 */

#ifndef BDN_H
#define	BDN_H
#define NEURON_TYPE_BDN "binary decision neuron"

#include "nn-simulator/main/model/Neuron.h"
#include <memory>

using std::auto_ptr;

/**
 * Binary decision neuron class.
 * 
 */
class BDN : public Neuron {
public:
    BDN(int const &size, OutputFunction const * const f);
    virtual ~BDN();
    /**
     * Gets the value of the threshold of this <code>BDN</code>.
     * 
     * @return the value of the threshold of this <code>BDN</code>.
     * 
     */
    float const getThreshold() const;
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
    void setExpectedInput(auto_ptr<Input> input);
    /**
     * Gets the expected <code>Input</code> for this <code>BDN</code>.
     * 
     * @return the expected <code>Input</code> for this <code>BDN</code>.
     * 
     */
    Input const * const getExpectedInput() const;
    /**
     * Sets the necessary <code>Input</code> for this <code>BDN</code>.
     * For example, the expected input will differ from the necessary
     * input when modelling logical OR functions.
     * 
     * @param input the necessary <code>Input</code> for this 
     * <code>BDN</code>.
     * 
     */
    void setNecessaryInput(auto_ptr<Input> input);
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
    Input const * const getNecessaryInput() const;
protected:
    Output const calculateActivation(Input const &input) const;
private:
    float threshold;
    auto_ptr<Input> expectedInput;
    auto_ptr<Input> necessaryInput;
};

#endif	/* BDN_H */
