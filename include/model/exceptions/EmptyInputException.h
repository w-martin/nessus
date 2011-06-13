/* 
 * File:   EmptyInputException.h
 * Author: will
 *
 * Created on June 13, 2011, 8:30 AM
 */

#ifndef EMPTYINPUTEXCEPTION_H
#define	EMPTYINPUTEXCEPTION_H

#include <exception>

/**
 * Exception which indicates that an <code>Input</code> vector either is
 * empty and was used, or can only be empty (i.e. created with size = 0).
 * 
 */
class EmptyInputException : public std::exception {

    virtual const char* what() const throw () {
        return "Error. Empty Input vector.";
    }
};

#endif	/* EMPTYINPUTEXCEPTION_H */

