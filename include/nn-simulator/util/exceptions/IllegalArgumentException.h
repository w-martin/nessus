/* 
 * File:   IllegalArgumentException.h
 * Author: will
 *
 * Created on June 26, 2011, 11:36 PM
 */

#ifndef ILLEGALARGUMENTEXCEPTION_H
#define	ILLEGALARGUMENTEXCEPTION_H

#define ILLEGAL_ARGUMENT_MESSAGE "Error. Illegal argument(s)."

#include "util/exceptions/Exception.h"

/**
 * Exception class which indicates that a method was called with 
 * one or more illegal arguments.
 * 
 */
class IllegalArgumentException : public Exception {
public:

    IllegalArgumentException() : Exception(ILLEGAL_ARGUMENT_MESSAGE) {
    }

    IllegalArgumentException(const char *message) : Exception(message) {
    }
};

#endif	/* ILLEGALARGUMENTEXCEPTION_H */

