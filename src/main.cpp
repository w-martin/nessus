/* 
 * File:   main.cpp
 * Author: Will
 *
 * Created on 04 June 2011, 16:05
 */

#include <cstdlib>
#include <iostream>

#include "net/Weight.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Hello" << "\n";

    Weight *w = new Weight(5);
    cout << (*w).getMultiplier(4);

    return 0;
}

