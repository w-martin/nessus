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
    Output(float value);
    virtual ~Output();
    float getValue();
private:
    float value;
};

#endif	/* OUTPUT_H */

