/* 
 * File:   Neuron.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 19:01
 */

#include <string>

#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/main/model/Architecture.h"

Neuron::Neuron(auto_ptr<Weights> weights,
        OutputFunction const * const outputFunction)
throw (IllegalArgumentException) {
    if (!weights.get())
        throw IllegalArgumentException("Error. No weights.");
    if (NULL == outputFunction)
        throw IllegalArgumentException("Error. No output function.");
    Neuron::weights = weights;
    Neuron::outputFunction = outputFunction;
}

Neuron::~Neuron() {
}

char const *Neuron::getType() const {
    return NEURON_TYPE_STD;
}

Output const Neuron::processInput(Input const &input) const {
    Output activation = calculateActivation(input);
    return applyOutputFunction(activation.getValue());
}

Output const Neuron::calculateActivation(Input const &input) const {
    float total = 0.0f;
    for (int i = 0; i < input.getSize(); i++) {
        total += input.getValue(i) * weights->getValue(i);
    }
    Output output = Output(total);
    return output;
}

Output const Neuron::applyOutputFunction(float const activation) const {
    return outputFunction->function(activation);
}

Output const * const Neuron::getExpectedOutput() const {
    if (expectedOutput.get())
        return expectedOutput.get();
    else
        return NULL;
}

void Neuron::setExpectedOutput(auto_ptr<Output> expectedOutput)
throw (IllegalArgumentException) {
    if (!expectedOutput.get())
        throw IllegalArgumentException();
    Neuron::expectedOutput = expectedOutput;
}

Weights * const Neuron::getWeights() const {
    return weights.get();
}

OutputFunction const * const Neuron::getOutputFunction() const {
    return outputFunction;
}
