/*
 * File:   Architecture.h
 * Author: Will
 *
 * Created on 06 June 2011, 16:12
 */

#ifndef ARCHITECTURE_H
#define	ARCHITECTURE_H

#include "nessus/trainer/Trainer.h"
#include "nessus/functions/OutputFunction.h"
#include "nessus/util/exceptions/IllegalArgumentException.h"
#include <memory>

using std::auto_ptr;

/**
 * Architecture class, for specifying the <code>OutputFunction</code>,
 * <code>Trainer</code>, <code>Neuron</code> type and maximum number of
 * <code>Layer</code> a <code>Net</code> may have.
 *
 */
class Architecture {
public:
  /**
   * Constructs the <code>Architecture</code> with the given
   * number of <code>Layer</code>s.
   *
   * @param noLayers the number of <code>Layer</code>s that this
   * <code>Architecture</code> can support. 0 indicates unlimited
   * layer support.
   * @param function the <code>OutputFunction</code> for this
   * <code>Architecture</code>.
   * @param trainer the <code>Trainer</code> for this
   * <code>Architecture</code>.
   * @throw IllegalArgumentException if any of the arguments are not
   * initialized.
   *
   */
  Architecture(int const noLayers, auto_ptr<OutputFunction> function,
               auto_ptr<Trainer> trainer, char const * const neuronType)
  throw (IllegalArgumentException);
  virtual ~Architecture();
  /**
   * Gets the maximum number of layers that this
   * <code>Architecture</code> can support. 0 indicates unlimited
   * layer support.
   *
   * @return the maximum number of layers that this
   * <code>Architecture</code> can support. 0 indicates unlimited
   * layer support.
   *
   */
  int const getMaxLayers() const;
  /**
   * Gets the <code>OutputFunction</code> of this
   * <code>Architecture</code>.
   *
   * @return the <code>OutputFunction</code> of this
   * <code>Architecture</code>.
   *
   */
  OutputFunction const * const getFunction() const;
  /**
   * Gets the <code>Trainer</code> of this <code>Architecture</code>.
   *
   * @return the <code>Trainer</code> of this
   * <code>Architecture</code>.
   *
   */
  Trainer const * const getTrainer() const;
  /*
   * Gets the type of <code>Neuron</code> that this
   * <code>Architecture</code> supports.
   *
   */
  char const * const getNeuronType() const;
private:
  int maxLayers;
  auto_ptr<OutputFunction> function;
  auto_ptr<Trainer> trainer;
  char const * neuronType;
};

#endif	/* ARCHITECTURE_H */

