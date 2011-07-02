/* 
 * File:   Neuron.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 19:01
 */

#include <string>

#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/main/model/Architecture.h"

Neuron::Neuron(Weights* w, OutputFunction *f)
throw (IllegalArgumentException*) {
    if (NULL == w
            || NULL == f)
        throw new IllegalArgumentException();
    Neuron::weights = w;
    Neuron::function = f;
    Neuron::expectedOutput = NULL;
}

Neuron::~Neuron() {
    delete weights;
    delete function;
    if (NULL != expectedOutput)
        delete expectedOutput;
}

const char *Neuron::getType() {
    return NEURON_TYPE_STD;
}

Output *Neuron::processInput(Input* input) throw (IllegalArgumentException*) {
    if (NULL == input)
        throw new IllegalArgumentException();
    Output* activation = calculateActivation(input);
    Output* result = applyOutputFunction(activation->getValue());
    return result;
}

Output *Neuron::calculateActivation(Input* input) {
    float total = 0.0f;
    for (int i = 0; i < input->getSize(); i++) {
        total += input->getValue(i) * weights->getValue(i);
    }
    Output *output = new Output(total);
    return output;
}

Output *Neuron::applyOutputFunction(float activation) {
    Output *result = function->function(activation);
    return result;
}

Output *Neuron::getExpectedOutput() {
    return Neuron::expectedOutput;
}

void Neuron::setExpectedOutput(Output* newExpectedOutput)
throw (IllegalArgumentException*) {
    if (NULL == newExpectedOutput)
        throw new IllegalArgumentException();
    Neuron::expectedOutput = newExpectedOutput;
}

Weights *Neuron::getWeights() {
    return Neuron::weights;
}
