/*
 * File:   LayerNotSetException.h
 * Author: will
 *
 * Created on June 13, 2011, 8:30 AM
 */

#ifndef LAYERNOTSETEXCEPTION_H
#define	LAYERNOTSETEXCEPTION_H

#define LAYER_NOT_SET_MESSAGE "Error. Layer not set."

#include "nessus/util/exceptions/Exception.h"

/**
 * Exception which indicates that a layer was not set when it
 * should have been.
 *
 */
class LayerNotSetException : public Exception {
public:

  LayerNotSetException() : Exception(LAYER_NOT_SET_MESSAGE) {
  }

  LayerNotSetException(const char * const message)
    : Exception(message) {
  }

};

#endif	/* LAYERNOTSETEXCEPTION_H */

