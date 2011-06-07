/* 
 * File:   Neuron.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 19:01
 */

#include "Neuron.h"
#include "Architecture.h"

Neuron::Neuron(Weight* w, OutputFunction *f) {
    Neuron::weight = w;
    Neuron::function = f;
    Neuron::expectedOutput = NULL;
}

Neuron::~Neuron() {
    if (NULL != Neuron::weight)
        Neuron::weight->~Weight();
    if (NULL != Neuron::function)
        Neuron::function->~OutputFunction();
    if (NULL != Neuron::expectedOutput)
        Neuron::expectedOutput->~Output();
}

Output *Neuron::processInput(Input* input) {
    Output* activation = calculateActivation(input);
    Output* result = applyOutputFunction(activation->getValue());
    return result;
}

Output *Neuron::calculateActivation(Input* input) {
    float total = 0.0f;
    for (int i = 0; i < input->getSize(); i++) {
        total += input->getValue(i) * weight->getMultiplier(i);
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

void Neuron::setExpectedOutput(Output* newExpectedOutput) {
    Neuron::expectedOutput = newExpectedOutput;
}

Weight *Neuron::getWeights() {
    return Neuron::weight;
}
