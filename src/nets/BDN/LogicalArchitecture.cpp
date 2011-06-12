/* 
 * File:   LogicalArchitecture.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 09:45
 */

#include "nets/BDN/LogicalArchitecture.h"
#include "nets/BDN/BDNTrainer.h"
#include "functions/HeavisideFunction.h"

LogicalArchitecture::LogicalArchitecture() : Architecture(0) {
    setFunction(new HeavisideFunction());
    setTrainer(new BDNTrainer());
}

LogicalArchitecture::~LogicalArchitecture() {
}

