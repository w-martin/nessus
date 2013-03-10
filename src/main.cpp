/*
 * File:   main.cpp
 * Author: Will
 *
 * Created on 04 June 2011, 16:05
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>

#include "nessus/nets/NetFactory.h"
#include "nessus/nets/BDN/realisations/ORnet.h"

using namespace std;

/*
 * Main.
 */
int main(int argc, char** argv) {
  cout << "Creating OR net." << "\n";

  auto_ptr<Net> net = Factory<Net, const char*>::createInstance(
                        NET_TYPE_ORNET, 2);

  cout << "Created OR net." << "\n";

  Input input(2);

  cout << "Created input." << "\n";

  float f0 = 1.0f;
  float f1 = 0.0f;

  input.setValue(0, f0);
  input.setValue(1, f1);

  cout << "Set inputs to " << f0 << " and " << f1 << "." << "\n";

  cout << "OR = " << net->processInput(input).getValue() << ".\n";

  return 0;
}
