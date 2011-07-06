/* 
 * File:   MockArchitecture.h
 * Author: Will
 * 
 * Created on 03 July, 09:56
 */

#include "gmock/gmock.h"
#include "nn-simulator/main/model/Architecture.h"
#include "nn-simulator/test/functions/MockOutputFunction.h"

class MockArchitecture : public Architecture {
public:

    MockArchitecture() : Architecture(2,
    auto_ptr<OutputFunction>(new MockOutputFunction()),
    auto_ptr<Trainer>(new Trainer())) {
    }
};
