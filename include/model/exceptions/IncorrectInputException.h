/* 
 * File:   IncorrectInputException.h
 * Author: Will
 *
 * Created on 10 June 2011, 09:57
 */

#ifndef INCORRECTINPUTEXCEPTION_H
#define	INCORRECTINPUTEXCEPTION_H

#include <exception>

/**
 * Exception class which indicates that a <code>Net</code> was asked
 * to process an <code>Input</code> of the wrong size.
 * 
 */
class IncorrectInputException : public std::exception {

    virtual const char* what() const throw () {
        return "Attempted to process an input of the wrong size.";
    }
};

#endif	/* INCORRECTINPUTEXCEPTION_H */

