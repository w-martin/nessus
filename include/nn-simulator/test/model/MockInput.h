/* 
 * File:   MockInput.cpp
 * Author: Will
 * 
 * Created on 10th July, 17:07
 */

#include "gmock/gmock.h"
#include "nn-simulator/main/model/Input.h"

class MockInput : public Input {
public:
    MockInput() : Input(1) {
    }
};
