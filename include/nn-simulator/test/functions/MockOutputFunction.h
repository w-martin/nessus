/* 
 * File:   MockOutputFunction.h
 * Author: will
 *
 * Created on 02 July, 2011, 11:26 AM
 */

#ifndef MOCKOUTPUTFUNCTION_H
#define	MOCKOUTPUTFUNCTION_H

#include "nn-simulator/main/functions/OutputFunction.h"

class MockOutputFunction : public OutputFunction {
public:

    MockOutputFunction() {
    }

    virtual ~MockOutputFunction() {
    }

    Output function(float const activation) const {
        return Output(0.0f);
    }
};

#endif
