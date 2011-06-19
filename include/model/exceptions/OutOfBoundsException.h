/* 
 * File:   OutOfBoundsException.h
 * Author: will
 *
 * Created on June 13, 2011, 8:22 AM
 */

#ifndef OUTOFBOUNDSEXCEPTION_H
#define	OUTOFBOUNDSEXCEPTION_H

#define OUT_OF_BOUNDS_MESSAGE "Attempted to access an array outside of its bounds."

#include <string.h>
#include "model/exceptions/Exception.h"

/**
 * Exception class which indicates that something attempted to access an
 * array outside of its bounds.
 * 
 */
class OutOfBoundsException : public Exception {
public:

    OutOfBoundsException() : Exception(OUT_OF_BOUNDS_MESSAGE) {
    }

    OutOfBoundsException(const char *message) : Exception(message) {
    }
};

#endif	/* OUTOFBOUNDSEXCEPTION_H */

