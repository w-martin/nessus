/* 
 * File:   OutputFunction.h
 * Author: Will
 *
 * Created on 05 June 2011, 12:46
 */

#ifndef OUTPUTFUNCTION_H
#define	OUTPUTFUNCTION_H

/**
 * Output function interface.
 * 
 */
class OutputFunction {
public:
    static float computeOutput(float activation, float threshold);
private:
};

#endif	/* OUTPUTFUNCTION_H */

