/* 
 * File:   ORnet.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 18:06
 */

#include "nets/BDN/realisations/ORnet.h"
#include "nets/BDN/BDNTrainer.h"
#include "nets/BDN/BDN.h"
#include <stdlib.h>

using namespace std;

ORnet::ORnet(int noInputs) : Net(new LogicalArchitecture(), 1, noInputs) {
    createInputVectors();
    createLayers();
    createNeurons();
}

ORnet::~ORnet() {
    expectedInput->~Input();
    necessaryInput->~Input();
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
    BDNTrainer *trainer = (BDNTrainer*) getArchitecture()->getTrainer();
    trainer->initWeights(n);
    trainer->setThreshold(n);
    getLayer(0)->setNeuron(0, n);
}
