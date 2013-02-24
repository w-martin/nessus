/* 
 * File:   MockBDN.h
 * Author: Will
 * 
 * Created on 14 July, 20:27
 */

#include "nessus/functions/MockOutputFunction.h"
#include "nessus/nets/BDN/BDN.h"

class MockBDN : public BDN {
public:

    MockBDN() : BDN(1, new MockOutputFunction()) {
    }
};
