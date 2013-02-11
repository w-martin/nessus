/* 
 * File:   MockLayer.h
 * Author: Will
 * 
 * Created on 03 July, 10:06
 */

#include "nn-simulator/main/model/Layer.h"

class MockLayer : public Layer {
public:

    MockLayer() : Layer(0, false) {
    }
    virtual Input const processInput(Input const &input) const {
        return input;
    }
};
