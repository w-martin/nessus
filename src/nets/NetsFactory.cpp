/* 
 * File:   NetsFactory.cpp
 * Author: will
 *
 * Created on June 26, 2011, 9:10 PM
 */

#include "nn-simulator/main/nets/NetsFactory.h"
#include <string.h>

auto_ptr<Net> NetsFactory::createInstance(
        const char * const netIdentifier, int const noInputs)
throw (UnsupportedConfigurationException) {
    if (0 == strcmp(ORNET_ID, netIdentifier)) {
        return auto_ptr<Net > (new ORnet(noInputs));
    }
    throw UnsupportedConfigurationException("Error. Unknown net.");
}