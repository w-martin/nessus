/*
 * File:   Output.cpp
 * Author: Will
 *
 * Created on 06 June 2011, 16:04
 */

#include "nessus/model/Output.h"

Output::Output(float const value) {
  Output::value = value;
}

Output::Output(const Output& orig) {
  value = orig.getValue();
}

Output::~Output() {
}

Output &Output::operator=(const Output &other) {
  value = other.getValue();
  return *this;
}

float const Output::getValue() const {
  return value;
}
