/* 
 * File:   UnsupportedLayersException.h
 * Author: Will
 *
 * Created on 08 June 2011, 17:03
 */

#ifndef UNSUPPORTEDLAYERSEXCEPTION_H
#define	UNSUPPORTEDLAYERSEXCEPTION_H

#define UNSUPPORTED_LAYERS_MESSAGE "Attempted to create a Net with an unsupported number of layers."

#include "model/exceptions/Exception.h"

/**
 * Exception class which indicates that a <code>Net</code> was created
 * which had an unsupported number of <code>Layer</code>s.
 * 
 */
class UnsupportedLayersException : public Exception {
public:

    UnsupportedLayersException() : Exception(UNSUPPORTED_LAYERS_MESSAGE) {

    }

    UnsupportedLayersException(const char *message) : Exception(message) {

    }
};

#endif	/* UNSUPPORTEDLAYERSEXCEPTION_H */

