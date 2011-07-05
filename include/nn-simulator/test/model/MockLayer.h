/* 
 * File:   MockLayer.h
 * Author: Will
 * 
 * Created on 03 July, 10:06
 */

#include "gmock/gmock.h"
#include "nn-simulator/main/model/Layer.h"

class MockLayer : public Layer {
public:

    MockLayer() : Layer(0, false) {
    }
};
