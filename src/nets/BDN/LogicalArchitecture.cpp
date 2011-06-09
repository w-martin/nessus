/* 
 * File:   LogicalArchitecture.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 09:45
 */

#include "LogicalArchitecture.h"
#include "../../functions/HeavisideFunction.h"
#include "BDNTrainer.h"

LogicalArchitecture::LogicalArchitecture() : Architecture(2) {
    setFunction(new HeavisideFunction());
    setTrainer(new BDNTrainer());
}

LogicalArchitecture::~LogicalArchitecture() {
}

