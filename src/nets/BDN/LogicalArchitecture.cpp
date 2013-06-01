/*
 * File:   LogicalArchitecture.cpp
 * Author: Will
 *
 * Created on 09 June 2011, 09:45
 */

#include "nessus/nets/BDN/LogicalArchitecture.h"
#include "nessus/nets/BDN/BDNTrainer.h"
#include "nessus/functions/HeavisideFunction.h"
#include "nessus/nets/BDN/BDN.h"

LogicalArchitecture::LogicalArchitecture() : Architecture(
    0,
    unique_ptr<OutputFunction> (new HeavisideFunction()),
    unique_ptr<Trainer>(new BDNTrainer()),
    NEURON_TYPE_BDN
  ) {
}

LogicalArchitecture::~LogicalArchitecture() {
}

