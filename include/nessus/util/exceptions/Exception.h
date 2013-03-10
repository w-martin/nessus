/*
 * File:   Exception.h
 * Author: will
 *
 * Created on June 19, 2011, 6:14 PM
 */

#ifndef EXCEPTION_H
#define	EXCEPTION_H

#include <exception>

/**
 * Custom <code>Exception</code> class.
 *
 * @param message the message that will be printed as the cause for this
 * <code>Exception</code>.
 *
 */
class Exception : public std::exception {
public:

  Exception(const char *message) {
    Exception::message = message;
  }

  virtual ~Exception() throw () {
  }

  virtual const char * what() const throw () {
    return message;
  }
private:
  /**
   * The string which is the reason why this <code>Exception</code> was
   * thrown.
   *
   */
  const char *message;
};

#endif	/* EXCEPTION_H */

