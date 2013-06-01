/*
 * File:   ORnet.cpp
 * Author: Will
 *
 * Created on 09 June 2011, 18:06
 */

#include "nessus/nets/BDN/realisations/ORnet.h"
#include "nessus/nets/BDN/BDNTrainer.h"
#include "nessus/nets/BDN/BDN.h"
#include "nessus/nets/NeuronFactory.h"
#include <stdlib.h>

using namespace std;

ORnet::ORnet(int const noInputs) :
  Net(unique_ptr<Architecture>(new LogicalArchitecture()), 1, noInputs,
      NET_TYPE_ORNET) {
  ORnet::noInputs = noInputs;
  createInputVectors();
  createLayers();
  createNeurons();
}

ORnet::~ORnet() {
}

void ORnet::createInputVectors() {
  expectedInput = new Input(noInputs);
  necessaryInput = new Input(noInputs);
  for (int i = 0; i < getNoInputs(); i++) {
    expectedInput->setValue(i, 1.0f);
    necessaryInput->setValue(i, (i == 0) ? 1.0f : 0.0f);
  }
}

void ORnet::createLayers() {
  Layer *l = new Layer(1, false);
  setLayer(0, unique_ptr<Layer > (l));
}

void ORnet::createNeurons() {
  unique_ptr<BDN> n = std::move(Factory<BDN, Architecture>::
                    createInstance((*getArchitecture()), getNoInputs()));
  n->setExpectedInput(unique_ptr<Input > (expectedInput));
  n->setNecessaryInput(unique_ptr<Input > (necessaryInput));
  BDNTrainer *trainer = (BDNTrainer*) getArchitecture()->getTrainer();
  trainer->initWeights(n.get());
  trainer->setThreshold(n.get());
  unique_ptr<Neuron> neuronPointer = unique_ptr<Neuron > (n);
  getLayer(0)->setNeuron(0, neuronPointer);
}
