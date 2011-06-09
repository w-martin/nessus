/* 
 * File:   ORnet.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 18:06
 */

#include "ORnet.h"
#include "../BDN.h"

ORnet::ORnet(int noInputs) : Net(new LogicalArchitecture(), 1, noInputs) {
    createInputVectors();
    createLayers();
    createNeurons();
}

ORnet::~ORnet() {
}

void ORnet::createInputVectors() {
    expectedInput = new Input(getNoInputs());
    necessaryInput = new Input(getNoInputs());
    for (int i = 0; i < getNoInputs(); i++) {
        expectedInput->setValue(i, 1.0f);
        necessaryInput->setValue(i, (i == 0) ? 1.0f : 0.0f);
    }
}

void ORnet::createLayers() {
    Layer *l = new Layer(1, false);
    setLayer(0, l);
}

void ORnet::createNeurons() {
    Weights *w = new Weights(getNoInputs());
    BDN *n = new BDN(w, getArchitecture()->getFunction());
    n->setExpectedInput(expectedInput);
    n->setNecessaryInput(necessaryInput);
    getArchitecture()->getTrainer()->initWeights(n);
    getLayer(0)->setNeuron(0, n);
}
