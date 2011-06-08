/* 
 * File:   main.cpp
 * Author: Will
 *
 * Created on 04 June 2011, 16:05
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>

#include "net/Weights.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    std::cout << "Hello" << "\n";

    Weights *w = new Weights(5);
    w->init();
    printf("%f\n", w->getMultiplier(4));

    return 0;
}
