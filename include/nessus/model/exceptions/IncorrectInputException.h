/* 
 * File:   IncorrectInputException.h
 * Author: Will
 *
 * Created on 10 June 2011, 09:57
 */

#ifndef INCORRECTINPUTEXCEPTION_H
#define	INCORRECTINPUTEXCEPTION_H

#define INCORRECT_INPUT_MESSAGE "Attempted to process an input of the wrong size."

#include "nessus/util/exceptions/Exception.h"

/**
 * Exception class which indicates that a <code>Net</code> was asked
 * to process an <code>Input</code> of the wrong size.
 * 
 */
class IncorrectInputException : public Exception {
public:

    IncorrectInputException() : Exception(INCORRECT_INPUT_MESSAGE) {

    }

    IncorrectInputException(const char * const message) 
    : Exception(message) {

    }
};

#endif	/* INCORRECTINPUTEXCEPTION_H */
