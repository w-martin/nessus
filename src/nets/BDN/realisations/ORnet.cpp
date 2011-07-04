/* 
 * File:   ORnet.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 18:06
 */

#include "nn-simulator/main/nets/BDN/realisations/ORnet.h"
#include "nn-simulator/main/nets/BDN/BDNTrainer.h"
#include "nn-simulator/main/nets/BDN/BDN.h"
#include <stdlib.h>

using namespace std;

ORnet::ORnet(int noInputs) :
Net(auto_ptr<Architecture>(new LogicalArchitecture()), 1, noInputs) {
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
    setLayer(0, auto_ptr<Layer > (l));
}

void ORnet::createNeurons() {
    auto_ptr<Weights> weights(new Weights(getNoInputs()));
    BDN *n = new BDN(weights, getArchitecture()->getFunction());
    n->setExpectedInput(auto_ptr<Input > (expectedInput));
    n->setNecessaryInput(auto_ptr<Input > (necessaryInput));
    BDNTrainer *trainer = (BDNTrainer*) getArchitecture()->getTrainer();
    trainer->initWeights(n);
    trainer->setThreshold(n);
    auto_ptr<Neuron> neuronPointer = auto_ptr<Neuron > (n);
    getLayer(0)->setNeuron(0, neuronPointer);
}
