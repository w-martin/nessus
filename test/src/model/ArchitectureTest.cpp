/* 
 * File:   ArchitectureTest.cpp
 * Author: will
 * 
 * Created on July 2, 2011, 7:57 PM
 */

#include <memory>

#include <boost/test/unit_test.hpp>
#include "nessus/model/Architecture.h"
#include "nessus/functions/MockOutputFunction.h"

#define NEURON_TYPE_TEST "test neuron type"

struct ArchitectureTest {

    ArchitectureTest() {
        noLayers = 1;
        outputFunctionMock = new MockOutputFunction();
        trainer = new Trainer();
        auto_ptr<OutputFunction> outputFunctionPointer(outputFunctionMock);
        auto_ptr<Trainer> trainerPointer(trainer);
        architecture = new Architecture(noLayers, outputFunctionPointer,
                trainerPointer, NEURON_TYPE_TEST);
    }

    virtual ~ArchitectureTest() {
        delete architecture;
    }
    int noLayers;
    Architecture *architecture;
    OutputFunction *outputFunctionMock;
    Trainer *trainer;
};

BOOST_FIXTURE_TEST_SUITE(ArchitectureTests, ArchitectureTest)

/*
 * Tests whether the constructor throws an exception when the arguments
 * are not initialized.
 * 
 */
BOOST_AUTO_TEST_CASE(ConstructorExceptionTest) {
    auto_ptr<OutputFunction> outputFunctionPointer(
            new MockOutputFunction());
    auto_ptr<Trainer> trainerPointer(new Trainer());

    auto_ptr<OutputFunction> tmp1;
    BOOST_CHECK_THROW(new Architecture(0,
            tmp1, trainerPointer, NEURON_TYPE_TEST),
            IllegalArgumentException);

    auto_ptr<Trainer> tmp2;
    BOOST_CHECK_THROW(new Architecture(0,
            outputFunctionPointer, tmp2, NEURON_TYPE_TEST),
            IllegalArgumentException);
}

/*
 * Tests whether the maximum number of layers is returned correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(GetMaxLayersTest) {
    BOOST_CHECK_EQUAL(noLayers, architecture->getMaxLayers());
}

/*
 * Tests whether the function is returned correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(GetFunctionTest) {
    BOOST_CHECK_EQUAL(outputFunctionMock, architecture->getFunction());
}

/*
 * Tests whether the trainer is returned correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(GetTrainerTest) {
    BOOST_CHECK_EQUAL(trainer, architecture->getTrainer());
}

/*
 * Tests whether the neuron type is returned correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(GetNeuronTypeTest) {
    BOOST_CHECK_EQUAL(NEURON_TYPE_TEST, architecture->getNeuronType());
}

BOOST_AUTO_TEST_SUITE_END()
