/* 
 * File:   BDNTrainer.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 13:39
 */

#include "nets/BDN/BDNTrainer.h"
#include <string.h>
#include <iostream>

BDNTrainer::BDNTrainer() {
}

BDNTrainer::~BDNTrainer() {
}

void setBinaryWeights(BDN *n) {
    Input *in = n->getExpectedInput();
    Weights *ws = n->getWeights();

    if (ws->getSize() >= in->getSize()) {
        for (int i = 0; i < in->getSize(); i++) {
            if (in->getValue(i) == 1.0f)
                ws->setMultiplier(i, 1.0f);
            else
                ws->setMultiplier(i, -1.0f);
        }
    }
}

void BDNTrainer::initWeights(Neuron* n) {
    if (0 == strcmp(n->getType(), NEURON_TYPE_BDN)) {
        BDN *bdn = (BDN*) n;
        setBinaryWeights(bdn);
    }
}

void BDNTrainer::setThreshold(BDN* n) {
    Input *necessaryInput = n->getNecessaryInput();
    float threshold = necessaryInput->getSize() - 0.5f;
    for (int i = 0; i < necessaryInput->getSize(); i++) {
        if (necessaryInput->getValue(i) < 0.5f)
            threshold -= 1.0f;
    }
    std::cout << "setting threshold to " << threshold << "\n";
    n->setThreshold(threshold);
}
