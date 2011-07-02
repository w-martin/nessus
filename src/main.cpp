/* 
 * File:   main.cpp
 * Author: Will
 *
 * Created on 04 June 2011, 16:05
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>

#include "nn-simulator/main/nets/NetsFactory.h"
#include "nn-simulator/main/nets/BDN/realisations/ORnet.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Creating OR net!" << "\n";

    ORnet *net = (ORnet*) NetsFactory::createInstance(ORNET_ID, 2);

    cout << "Created OR net" << "\n";

    delete net;

    cout << "Deleted OR net." << "\n";

    return 0;
}
