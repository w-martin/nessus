/* 
 * File:   Weight.h
 * Author: Will
 *
 * Created on 04 June 2011, 16:14
 */

#ifndef WEIGHT_H
#define	WEIGHT_H

#include <vector>

class Weight {
public:
    Weight(int noInputs);
    virtual ~Weight();
    /**
     * Gets the multiplier associated with the given input vector i.
     * 
     * @param i the input vector
     * @return the multiplier associated with the given input vector i.
     * 
     */
    double getMultiplier(int i);
private:
    double *multipliers;
};

#endif	/* WEIGHT_H */

