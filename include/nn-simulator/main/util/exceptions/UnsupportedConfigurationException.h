/* 
 * File:   UnsupportedConfigurationException.h
 * Author: will
 *
 * Created on June 26, 2011, 9:04 PM
 */

#ifndef UNSUPPORTEDCONFIGURATIONEXCEPTION_H
#define	UNSUPPORTEDCONFIGURATIONEXCEPTION_H

#define UNSUPPORT_CONFIGURATION_MESSAGE "Error. Unsupported configuration."

#include "nn-simulator/main/util/exceptions/Exception.h"

class UnsupportedConfigurationException : public Exception {
public:

    UnsupportedConfigurationException()
    : Exception(UNSUPPORT_CONFIGURATION_MESSAGE) {
    }

    UnsupportedConfigurationException(const char *message) :
    Exception(message) {
    }
};

#endif	/* UNSUPPORTEDCONFIGURATIONEXCEPTION_H */

