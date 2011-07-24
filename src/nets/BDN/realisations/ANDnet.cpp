/* 
 * File:   ANDnet.cpp
 * Author: will
 * 
 * Created on July 24, 2011, 9:15 AM
 */

#include "nn-simulator/main/nets/BDN/realisations/ANDnet.h"
#include "nn-simulator/main/nets/BDN/BDNTrainer.h"
#include "nn-simulator/main/nets/BDN/BDN.h"
#include "nn-simulator/main/nets/NeuronFactory.h"

using namespace std;

ANDnet::ANDnet(int const noInputs) :
Net(auto_ptr<Architecture>(new LogicalArchitecture()), 1, noInputs,
NET_TYPE_ANDNET) {
    ANDnet::noInputs = noInputs;
    createInputVectors();
    createLayers();
    createNeurons();
}

ANDnet::~ANDnet() {
}

void ANDnet::createInputVectors() {
    expectedInput = new Input(noInputs);
    necessaryInput = new Input(noInputs);
    for (int i = 0; i < getNoInputs(); i++) {
        expectedInput->setValue(i, 1.0f);
        necessaryInput->setValue(i, 1.0f);
    }
}

void ANDnet::createLayers() {
    Layer *l = new Layer(1, false);
    setLayer(0, auto_ptr<Layer > (l));
}

void ANDnet::createNeurons() {
    auto_ptr<BDN> n = Factory<BDN, Architecture>::
            createInstance((*getArchitecture()), getNoInputs());
    n->setExpectedInput(auto_ptr<Input > (expectedInput));
    n->setNecessaryInput(auto_ptr<Input > (necessaryInput));
    BDNTrainer *trainer = (BDNTrainer*) getArchitecture()->getTrainer();
    trainer->initWeights(n.get());
    trainer->setThreshold(n.get());
    auto_ptr<Neuron> neuronPointer = auto_ptr<Neuron > (n);
    getLayer(0)->setNeuron(0, neuronPointer);
}
