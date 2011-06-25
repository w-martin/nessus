/* 
 * File:   Output.h
 * Author: Will
 *
 * Created on 05 June 2011, 12:28
 */

#ifndef OUTPUT_H
#define	OUTPUT_H

/**
 * Output object from neurons.
 * 
 */
class Output {
public:
    /**
     * Initialises the <code>Output</code> object with the given
     * value v.
     * 
     * @param v the value to initialise the <code>Output</code>
     * object with.
     * 
     */
    Output(float v);
    virtual ~Output();
    /**
     * Gets the value of the <code>Output</code> object.
     * 
     * @return the value of the <code>Output</code> object.
     * 
     */
    float getValue();
private:
    float value;
};

#endif	/* OUTPUT_H */

