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
     * Initializes the <code>Output</code> object with the given
     * value value.
     * 
     * @param value the value to initialize the <code>Output</code>
     * object with.
     * 
     */
    Output(float value);
    Output(const Output &orig);
    virtual ~Output();
    /**
     * Gets the value of the <code>Output</code> object.
     * 
     * @return the value of the <code>Output</code> object.
     * 
     */
    float getValue() const;
private:
    float value;
};

#endif	/* OUTPUT_H */

