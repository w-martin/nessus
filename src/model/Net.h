/* 
 * File:   Net.h
 * Author: Will
 *
 * Created on 08 June 2011, 16:36
 */

#ifndef NET_H
#define	NET_H

#include "Architecture.h"
#include "Layer.h"
#include "UnsupportedLayersException.h"

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
     * 
     */
    Net(Architecture *a, int noLayers) throw (UnsupportedLayersException);
    virtual ~Net();
    /**
     * Gets the number of <code>Layer</code>s of this <code>Net</code>.
     * 
     * @return the number of <code>Layer</code>s of this 
     * <code>Net</code>.
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
     * Gets the <code>Architecture</code> that this <code>Net</code>
     * implements.
     * 
     * @return the <code>Architecture</code> that this <code>Net</code>
     * implements.
     * 
     */
    Architecture *getArchitecture();
private:
    int size;
    Layer **layers;
    Architecture *architecture;
};

#endif	/* NET_H */

