/* 
 * File:   NetsFactory.h
 * Author: will
 *
 * Created on June 26, 2011, 8:52 PM
 */

#ifndef NETSFACTORY_H
#define	NETSFACTORY_H

#include "nn-simulator/main/model/Net.h"
#include "nn-simulator/main/util/exceptions/UnsupportedConfigurationException.h"
#include "nn-simulator/main/nets/BDN/realisations/ORnet.h"
#include <memory>

using std::auto_ptr;

/**
 * Factory for creating <code>Nets</code>.
 * 
 */
class NetsFactory {
public:
    static auto_ptr<Net> createInstance(
    const char * const netIdentifier, int const noInputs)
    throw (UnsupportedConfigurationException);
};

#endif	/* NETSFACTORY_H */

