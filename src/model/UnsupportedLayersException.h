/* 
 * File:   UnsupportedLayersException.h
 * Author: Will
 *
 * Created on 08 June 2011, 17:03
 */

#ifndef UNSUPPORTEDLAYERSEXCEPTION_H
#define	UNSUPPORTEDLAYERSEXCEPTION_H

#include <exception>

/**
 * Exception class which indicates that a <code>Net</code> was created
 * which had an unsupported number of <code>Layer</code>s.
 * 
 */
class UnsupportedLayersException : public std::exception {

    virtual const char* what() const throw () {
        return "Attempted to create a Net with an unsupported number"
        "of layers.";
    }
};

#endif	/* UNSUPPORTEDLAYERSEXCEPTION_H */

