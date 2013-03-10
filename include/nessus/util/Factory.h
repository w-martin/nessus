/*
 * File:   Factory.h
 * Author: will
 *
 * Created on July 9, 2011, 11:00 AM
 */

#ifndef FACTORY_H
#define	FACTORY_H

#include "nessus/util/exceptions/UnsupportedConfigurationException.h"
#include <memory>

using std::auto_ptr;

/**
 * Factory interface which creates instances of class T given a
 * construction object of class C.
 *
 */
template <class T, class C>
class Factory {
public:

  /**
   * Creates an instance of class T, given the construction object C.
   *
   * @param C the object which will be used during the construction of
   * an object of class T.
   * @return auto_ptr<T> auto pointer to the created object, to transfer
   * ownership to the caller.
   * @throw UnsupportedConfigurationException if the configuration of T with
   * construction object C is not supported by any implementation.
   *
   */
  static auto_ptr<T> createInstance(const C &constructionObject)
  throw (UnsupportedConfigurationException) {
    throw UnsupportedConfigurationException();
  }

  /**
   * Creates an instance of class T, given the construction object C.
   *
   * @param C the object which will be used during the construction of
   * an object of class T.
   * @param size the size the object should be.
   * @return an auto pointer to the created object, to transfer
   * ownership to the caller.
   * @throw UnsupportedConfigurationException if the configuration of T with
   * construction object C is not supported by any implementation.
   *
   */
  static auto_ptr<T> createInstance(const C &constructionObject,
                                    const int &size)
  throw (UnsupportedConfigurationException) {
    throw UnsupportedConfigurationException();
  }
};

#endif	/* FACTORY_H */

