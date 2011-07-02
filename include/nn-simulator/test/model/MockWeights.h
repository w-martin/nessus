/* 
 * File:   MockWeights.cpp
 * Author: Will
 * 
 * Created on 02 July, 18:14
 */

#include "gmock/gmock.h"
#include "nn-simulator/main/model/Weights.h"

class MockWeights : public Weights {
public:
    MockWeights() : Weights(1) {
    }
};
