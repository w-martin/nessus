/* 
 * File:   Neuron.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 19:01
 */

#include <string>

#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/main/model/Architecture.h"

Neuron::Neuron(auto_ptr<Weights> weights, OutputFunction *outputFunction)
throw (IllegalArgumentException*) {
    if (!weights.get()
            || NULL == outputFunction)
        throw new IllegalArgumentException();
    Neuron::weights = weights;
    Neuron::outputFunction = outputFunction;
}

Neuron::~Neuron() {
}

const char *Neuron::getType() {
    return NEURON_TYPE_STD;
}

Output *Neuron::processInput(Input* input) throw (IllegalArgumentException*) {
    if (NULL == input)
        throw new IllegalArgumentException();
    Output* activation = calculateActivation(input);
    return applyOutputFunction(activation->getValue());
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
    return outputFunction->function(activation);
}

Output *Neuron::getExpectedOutput() {
    if (expectedOutput.get())
        return expectedOutput.get();
    else
        return NULL;
}

void Neuron::setExpectedOutput(auto_ptr<Output> expectedOutput)
throw (IllegalArgumentException*) {
    if (!expectedOutput.get())
        throw new IllegalArgumentException();
    Neuron::expectedOutput = expectedOutput;
}

Weights *Neuron::getWeights() {
    return weights.get();
}

OutputFunction *Neuron::getOutputFunction() {
    return outputFunction;
}
