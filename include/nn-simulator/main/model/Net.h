/* 
 * File:   Net.h
 * Author: Will
 *
 * Created on 08 June 2011, 16:36
 */

#ifndef NET_H
#define	NET_H

#include "nn-simulator/main/model/Architecture.h"
#include "nn-simulator/main/model/Layer.h"
#include "nn-simulator/main/model/exceptions/IncorrectInputException.h"
#include "nn-simulator/main/util/exceptions/UnsupportedConfigurationException.h"
#include "nn-simulator/main/util/exceptions/IllegalArgumentException.h"

/**
 * The network class. That is, a store of 
 * <code>Layer</code>s that may not exceed that maximum
 * number of supported <code>Layer</code>s of the implemented
 * <code>Architecture</code>.
 * 
 */
class Net {
public:
    /**
     * Default constructor.
     * 
     * @param a the <code>Architecture</code> that this <code>Net</code>
     * implements.
     * @param noLayers the number of <code>Layer</code>s that this
     * <code>Net</code> should have.
     * @throw UnsupportedConfigurationException if the number of layers
     * or inputs does not match a supported configuration.
     * @throw IllegalArgumentException if any of the arguments are illegal
     * i.e. if the <code>Architecture</code> is NULL.
     * 
     */
    Net(auto_ptr<Architecture> architecture,
            int const noLayers,
            int const noInputs)
    throw (UnsupportedConfigurationException, IllegalArgumentException);
    virtual ~Net();
    /**
     * Gets the number of <code>Layer</code>s of this <code>Net</code>.
     * 
     * @return the number of <code>Layer</code>s of this 
     * <code>Net</code>.
     * 
     */
    int const getSize() const;
    /**
     * Sets the <code>Layer</code> at the specified position to be 
     * the given <code>Architecture</code>.
     * 
     * @param i the position to set the <code>Layer</code> at.
     * @param newLayer the <code>Layer</code> to set.
     * 
     */
    void setLayer(int const i, auto_ptr<Layer> newLayer);
    /**
     * Gets the <code>Layer</code> at the specified position.
     * 
     * @param i the position to get the <code>Layer</code> from.
     * @return the <code>Layer</code> at the specified position.
     * 
     */
    Layer * const getLayer(int const i) const;
    /**
     * Gets the <code>Architecture</code> that this <code>Net</code>
     * implements.
     * 
     * @return the <code>Architecture</code> that this <code>Net</code>
     * implements.
     * 
     */
    Architecture const * const getArchitecture() const;
    /**
     * Gets the number of inputs that this <code>Net</code> receives.
     * 
     * @return the number of inputs that this <code>Net</code> receives.
     * 
     */
    int const getNoInputs() const;
    /**
     * Processes the given <code>Input</code> to produce this 
     * <code>Net</code>'s <code>Output</code>.
     * 
     * @param input the <code>Input</code> to process.
     * @return the <code>Output</code> from the given 
     * <code>Input</code>.
     * 
     */
    Output const processInput(Input const &input) const
    throw (IncorrectInputException);
protected:
    /**
     * Sets the number of inputs that this <code>Net</code> receives.
     * 
     * @param noInputs the number of inputs that this <code>Net</code> receives.
     * 
     */
    void setNoInputs(int const noInputs);
private:
    int size, noInputs;
    auto_ptr<Layer> *layers;
    auto_ptr<Architecture> architecture;
};

#endif	/* NET_H */

