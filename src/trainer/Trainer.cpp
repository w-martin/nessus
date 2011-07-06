/* 
 * File:   Trainer.h
 * Author: Will
 *
 * Created on 08 June 2011, 15:53
 */

#include "nn-simulator/main/trainer/Trainer.h"
#include <time.h>
#include <stdlib.h>

Trainer::Trainer() {
}

Trainer::~Trainer() {
}

void Trainer::initWeights(Neuron const &n) const {
    setRandomWeights(n);
}

void Trainer::setRandomWeights(Neuron const &n) const {
    Weights *w = n.getWeights();
    srand(time(NULL));
    for (int i = 0; i < w->getSize(); i++) {
        int random = rand();
        float multiplier = random / ((float) (2 * RAND_MAX));
        w->setValue(i, multiplier);
    }
}
