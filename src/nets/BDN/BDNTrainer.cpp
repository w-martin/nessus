/* 
 * File:   BDNTrainer.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 13:39
 */

#include "BDNTrainer.h"
#include "BDN.h"
#include <string.h>

BDNTrainer::BDNTrainer() {
}

BDNTrainer::~BDNTrainer() {
}

void setBinaryWeights(BDN *n) {
    Input *in = n->getExpectedInput();
    Weights *ws = n->getWeights();

    if (ws->getSize() >= in->getSize()) {
        for (int i = 0; i < in->getSize(); i++) {
            if (in->getValue(i) > 0.5f)
                ws->setMultiplier(i, 1);
            else
                ws->setMultiplier(i, -1);
        }
    }
}

void BDNTrainer::initWeights(Neuron* n) {
    if (0 == strcmp(n->getType(), NEURON_TYPE_BDN)) {
        BDN *bdn = (BDN*) n;
        setBinaryWeights(bdn);
    }
}
