/* 
 * File:   Architecture.h
 * Author: Will
 *
 * Created on 06 June 2011, 16:12
 */

#ifndef ARCHITECTURE_H
#define	ARCHITECTURE_H

#include "../trainer/Trainer.h"
#include "../functions/OutputFunction.h"

/**
 * Architecture class, for specifying the <code>OutputFunction</code>,
 * <code>Trainer</code> and maximum number of <code>Layer</code> a
 * <code>Net</code> may have.
 * 
 */
class Architecture {
public:
    /**
     * Constructs the <code>Architecture</code> with the given
     * number of <code>Layer</code>s.
     * 
     * @param noLayers the number of <code>Layer</code>s that this
     * <code>Architecture</code> can support. 0 indicates unlimited
     * layer support.
     * 
     */
    Architecture(int noLayers);
    virtual ~Architecture();
    /**
     * Gets the maximum number of layers that this 
     * <code>Architecture</code> can support. 0 indicates unlimited
     * layer support.
     * 
     * @return the maximum number of layers that this 
     * <code>Architecture</code> can support. 0 indicates unlimited
     * layer support.
     * 
     */
    int getMaxLayers();
    /**
     * Gets the <code>OutputFunction</code> of this 
     * <code>Architecture</code>.
     * 
     * @return the <code>OutputFunction</code> of this 
     * <code>Architecture</code>.
     * 
     */
    OutputFunction *getFunction();
    /**
     * Gets the <code>Trainer</code> of this <code>Architecture</code>.
     * 
     * @return the <code>Trainer</code> of this 
     * <code>Architecture</code>.
     * 
     */
    Trainer *getTrainer();
protected:
    /**
     * Sets the <code>OutputFunction</code> to be the given
     * <code>OutputFunction</code>.
     * 
     * @param newFunction the new <code>OutputFunction</code>.
     * 
     */
    void setFunction(OutputFunction *newFunction);
    /**
     * Sets the <code>Trainer</code> of this <code>Architecture</code>.
     * 
     * @param newTrainer the new <code>Trainer</code> of this 
     * <code>Architecture</code>.
     * 
     */
    void setTrainer(Trainer *newTrainer);
private:
    int maxLayers;
    OutputFunction *function;
    Trainer *trainer;
};

#endif	/* ARCHITECTURE_H */

