/*
 * File:   NeuronFactory.h
 * Author: will
 *
 * Created on July 10, 2011, 11:39 AM
 */

#ifndef NEURONFACTORY_H
#define	NEURONFACTORY_H

#include "nessus/util/Factory.h"
#include "nessus/model/Neuron.h"
#include "nessus/model/Architecture.h"
#include "nessus/nets/BDN/BDN.h"

template <>
class Factory<Neuron, Architecture> {
public:

  /**
   * Creates an instance of the Neuron specified by the given
   * neuronType.
   *
   * @param architecture the Architecture specifying the Neuron to create.
   * @param size the size the neuron should be.
   * @return an auto pointer to the created neuron, to transfer
   * ownership to the caller.
   * @throw UnsupportedConfigurationException if the neuron is unknown.
   *
   */
  static auto_ptr<Neuron> createInstance(const Architecture &architecture,
                                         const int &size)
  throw (UnsupportedConfigurationException) {
    if (0 == strcmp(NEURON_TYPE_BDN, architecture.getNeuronType())) {
      return auto_ptr<Neuron > (new BDN(size,
                                        architecture.getFunction()));
    }
    throw UnsupportedConfigurationException("Error. Unknown neuron.");
  }
};

template <>
class Factory<BDN, Architecture> {
public:

  /**
   * Creates an instance of a BDN if the Architecture given supports
   * it.
   *
   * @param architecture the Architecture specifying the Neuron to create.
   * @param size the size the Neuron should be.
   * @return an auto pointer to the created neuron, to transfer
   * ownership to the caller.
   * @throw UnsupportedConfigurationException if the neuron is unknown.
   *
   */
  static auto_ptr<BDN> createInstance(const Architecture &architecture,
                                      const int &size)
  throw (UnsupportedConfigurationException) {
    if (0 == strcmp(NEURON_TYPE_BDN, architecture.getNeuronType())) {
      return auto_ptr<BDN > (new BDN(size,
                                     architecture.getFunction()));
    }
    throw UnsupportedConfigurationException(
      "Error. BDN not supported by this Architecture.");
  }
};

#endif	/* NEURONFACTORY_H */

