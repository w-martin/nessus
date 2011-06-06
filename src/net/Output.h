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

    Output(float v) {
        Output::value = v;
    }
    virtual ~Output();

    float getValue() {
        return Output::value;
    }
private:
    float value;
};

#endif	/* OUTPUT_H */

