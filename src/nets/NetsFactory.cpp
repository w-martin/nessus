/* 
 * File:   NetsFactory.cpp
 * Author: will
 *
 * Created on June 26, 2011, 9:10 PM
 */

#include "nets/NetsFactory.h"
#include <string.h>

Net *NetsFactory::createInstance(const char* netIdentifier, int noInputs)
throw (UnsupportedConfigurationException*) {
    if(0 == strcmp(ORNET_ID, netIdentifier)){
        return new ORnet(noInputs);
    }
    throw new UnsupportedConfigurationException("Error. Unknown net.");
}