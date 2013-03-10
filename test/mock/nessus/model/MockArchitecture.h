/*
 * File:   MockArchitecture.h
 * Author: Will
 *
 * Created on 03 July, 09:56
 */

#include "nessus/model/Architecture.h"
#include "nessus/functions/MockOutputFunction.h"

#define NEURON_TYPE_MOCK "mock neuron type"

class MockArchitecture : public Architecture {
public:

  MockArchitecture() : Architecture(2,
                                      auto_ptr<OutputFunction>(new MockOutputFunction()),
                                      auto_ptr<Trainer>(new Trainer()),
                                      NEURON_TYPE_MOCK) {
  }
};
