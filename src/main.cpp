/* 
 * File:   main.cpp
 * Author: Will
 *
 * Created on 04 June 2011, 16:05
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>

#include "nets/BDN/functions/ORnet.h"
#include "functions/HeavisideFunction.h"
#include "nets/BDN/BDN.h"
#include "model/Weights.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    std::cout << "Hello" << "\n";

    ORnet *net = new ORnet(3);
    delete net;

    return 0;
}
