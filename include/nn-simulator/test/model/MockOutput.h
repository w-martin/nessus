/* 
 * File:   MockOutput.h
 * Author: Will
 *
 * Created on 02 July 2011, 17:35
 */

#include "gmock/gmock.h"
#include "nn-simulator/main/model/Output.h"

class MockOutput : public Output {
public:

    MockOutput() : Output(0.0f) {
    }

    MOCK_CONST_METHOD0(getValue,
            float());
};
