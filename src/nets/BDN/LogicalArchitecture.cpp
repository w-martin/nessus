/* 
 * File:   LogicalArchitecture.cpp
 * Author: Will
 * 
 * Created on 09 June 2011, 09:45
 */

#include "nn-simulator/main/nets/BDN/LogicalArchitecture.h"
#include "nn-simulator/main/nets/BDN/BDNTrainer.h"
#include "nn-simulator/main/functions/HeavisideFunction.h"

LogicalArchitecture::LogicalArchitecture()
: Architecture(0, auto_ptr<OutputFunction> (new HeavisideFunction()),
auto_ptr<Trainer>(new BDNTrainer())) {
}

LogicalArchitecture::~LogicalArchitecture() {
}

