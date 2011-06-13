/* 
 * File:   OutOfBoundsException.h
 * Author: will
 *
 * Created on June 13, 2011, 8:22 AM
 */

#ifndef OUTOFBOUNDSEXCEPTION_H
#define	OUTOFBOUNDSEXCEPTION_H

#include <exception>

/**
 * Exception class which indicates that something attempted to access an
 * array outside of its bounds.
 * 
 */
class OutOfBoundsException : public std::exception {

    virtual const char* what() const throw () {
        return "Attempted to access an array outside of its bounds.";
    }
};

#endif	/* OUTOFBOUNDSEXCEPTION_H */

