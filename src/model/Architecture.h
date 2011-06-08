/* 
 * File:   Architecture.h
 * Author: Will
 *
 * Created on 06 June 2011, 16:12
 */

#ifndef ARCHITECTURE_H
#define	ARCHITECTURE_H

#include "Layer.h"
#include "../trainer/Trainer.h"
#include "../functions/OutputFunction.h"

class Architecture {
public:
    /**
     * Constructs the <code>Architecture</code> with the given
     * number of <code>Layer</code>s.
     * 
     * @param noLayers the number of <code>Layer</code>s that this
     * <code>Architecture</code> should have.
     * 
     */
    Architecture(int noLayers);
    virtual ~Architecture();
    /**
     * Gets the size of this <code>Architecture</code> / net.
     * 
     * @return the size of this <code>Architecture</code> / net.
     * 
     */
    int getSize();
    /**
     * Sets the <code>Layer</code> at the specified position to be 
     * the given <code>Architecture</code>.
     * 
     * @param i the position to set the <code>Layer</code> at.
     * @param newLayer the <code>Layer</code> to set.
     * 
     */
    void setLayer(int i, Layer *newLayer);
    /**
     * Gets the <code>Layer</code> at the specified position.
     * 
     * @param i the position to get the <code>Layer</code> from.
     * @return the <code>Layer</code> at the specified position.
     * 
     */
    Layer *getLayer(int i);
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
    int size;
    Layer **layers;
    OutputFunction *function;
    Trainer *trainer;
};

#endif	/* ARCHITECTURE_H */
