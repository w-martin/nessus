/* 
 * File:   BDNTrainer.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 13:39
 */

#include "nn-simulator/main/nets/BDN/BDNTrainer.h"
#include <string.h>

BDNTrainer::BDNTrainer() {
}

BDNTrainer::~BDNTrainer() {
}

void setBinaryWeights(BDN * const n) {
    Input const * const in = n->getExpectedInput();
    Weights * const ws = n->getWeights();

    if (ws->getSize() >= in->getSize()) {
        for (int i = 0; i < in->getSize(); i++) {
            if (in->getValue(i) == 1.0f)
                ws->setValue(i, 1.0f);
            else
                ws->setValue(i, -1.0f);
        }
    }
}

void BDNTrainer::initWeights(Neuron* const n) const {
    if (0 == strcmp(n->getType(), NEURON_TYPE_BDN)) {
        BDN *bdn = (BDN*) n;
        setBinaryWeights(bdn);
    }
}

void BDNTrainer::setThreshold(BDN* const n) const {
    Input const * const necessaryInput = n->getNecessaryInput();
    float threshold = necessaryInput->getSize() - 0.5f;
    for (int i = 0; i < necessaryInput->getSize(); i++) {
        if (necessaryInput->getValue(i) < 0.5f)
            threshold -= 1.0f;
    }
    n->setThreshold(threshold);
}
