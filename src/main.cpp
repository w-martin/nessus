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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    std::cout << "Hello" << "\n";

    ORnet *net = new ORnet(1);
    cout << "created net" << "\n";
    net->~Net();
    cout << "destroyed net" << "\n";
//    Input *in = new Input(3);
//    cout << "created input" << "\n";
//    in->setValue(0, 0);
//    in->setValue(0, 1);
//    in->setValue(0, 0);
//    cout << "set input" << "\n";
//    cout << net->processInput(in)->getValue() << '\n';
//    cout << "processed input" << "\n";
//    net->~ORnet();
//    in->~Input();
//    free(net);
//    free(in);
//    cout << "freed memory" << "\n";

    return 0;
}
