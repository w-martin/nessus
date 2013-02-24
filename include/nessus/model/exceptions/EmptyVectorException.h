/* 
 * File:   EmptyVectorException.h
 * Author: will
 *
 * Created on June 13, 2011, 8:30 AM
 */

#ifndef EMPTYINPUTEXCEPTION_H
#define	EMPTYINPUTEXCEPTION_H

#define EMPTY_VECTOR_MESSAGE "Error. Empty vector."

#include "nessus/util/exceptions/Exception.h"

/**
 * Exception which indicates that a vector either is
 * empty and was used.
 * 
 */
class EmptyVectorException : public Exception {
public:

    EmptyVectorException() : Exception(EMPTY_VECTOR_MESSAGE) {
    }

    EmptyVectorException(const char * const message) 
    : Exception(message) {
    }

};

#endif	/* EMPTYINPUTEXCEPTION_H */

