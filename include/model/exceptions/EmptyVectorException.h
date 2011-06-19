/* 
 * File:   EmptyVectorException.h
 * Author: will
 *
 * Created on June 13, 2011, 8:30 AM
 */

#ifndef EMPTYINPUTEXCEPTION_H
#define	EMPTYINPUTEXCEPTION_H

#define EMPTY_VECTOR_MESSAGE "Error. Empty vector."

#include "model/exceptions/Exception.h"

/**
 * Exception which indicates that a  vector either is
 * empty and was used, or can only be empty (i.e. created with size = 0).
 * 
 */
class EmptyVectorException : public Exception {
public:

    EmptyVectorException() : Exception(EMPTY_VECTOR_MESSAGE) {
    }

    EmptyVectorException(const char *message) : Exception(message) {
    }

};

#endif	/* EMPTYINPUTEXCEPTION_H */

