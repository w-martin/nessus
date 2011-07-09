/* 
 * File:   Factory.cpp
 * Author: will
 * 
 * Created on July 9, 2011, 11:15 AM
 */


#include "nn-simulator/main/util/Factory.h"

template <class T, class C>
auto_ptr<T> Factory::createInstance(const C& constructionObject)
throw (UnsupportedConfigurationException) {
    throw UnsupportedConfigurationException();
}

template <class T, class C>
auto_ptr<T> Factory::createInstance(const C& constructionObject,
const int& size)
throw (UnsupportedConfigurationException) {
    throw UnsupportedConfigurationException();
}