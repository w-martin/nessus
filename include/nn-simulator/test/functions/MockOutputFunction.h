/* 
 * File:   MockOutputFunction.h
 * Author: will
 *
 * Created on 02 July, 2011, 11:26 AM
 */

#include "gmock/gmock.h"
#include "nn-simulator/main/functions/OutputFunction.h"

class MockOutputFunction : public OutputFunction {
public:
    MOCK_METHOD1(function,
            Output (float activation));
};
