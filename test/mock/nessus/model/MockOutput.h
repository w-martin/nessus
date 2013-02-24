/* 
 * File:   MockOutput.h
 * Author: Will
 *
 * Created on 02 July 2011, 17:35
 */

#include "nessus/model/Output.h"

class MockOutput : public Output {
public:

    MockOutput() : Output(0.0f) {
    }

    MockOutput(const MockOutput &orig) : Output(0.0f) {
    }
};
