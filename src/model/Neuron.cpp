/* 
 * File:   Neuron.cpp
 * Author: Will
 *
 * Created on 07 June 2011, 19:01
 */

#include <string>

#include "nn-simulator/main/model/Neuron.h"
#include "nn-simulator/main/model/Architecture.h"

Neuron::Neuron(int const &size,
        OutputFunction const * const outputFunction,
        char const * const neuronType)
throw (IllegalArgumentException) {
    if (0 == size)
        throw IllegalArgumentException("Error. Cannot create empty neuron.");
    if (NULL == outputFunction)
        throw IllegalArgumentException("Error. No output function.");
    Neuron::weights = new Weights(size);
    Neuron::outputFunction = outputFunction;
    Neuron::neuronType = neuronType;
}

Neuron::~Neuron() {
}

char const * const Neuron::getType() const {
    return neuronType;
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
    return weights;
}

OutputFunction const * const Neuron::getOutputFunction() const {
    return outputFunction;
}
