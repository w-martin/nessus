/* 
 * File:   NetsFactory.h
 * Author: will
 *
 * Created on June 26, 2011, 8:52 PM
 */

#ifndef NETSFACTORY_H
#define	NETSFACTORY_H

#include "model/Net.h"
#include "util/exceptions/UnsupportedConfigurationException.h"
#include "nets/BDN/realisations/ORnet.h"

/**
 * Factory for creating <code>Nets</code>.
 * 
 */
class NetsFactory {
public:
    static Net *createInstance(const char *netIdentifier, int noInputs) 
    throw (UnsupportedConfigurationException*);
};

#endif	/* NETSFACTORY_H */

