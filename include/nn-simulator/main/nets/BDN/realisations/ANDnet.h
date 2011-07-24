/* 
 * File:   ANDnet.h
 * Author: will
 *
 * Created on July 24, 2011, 9:15 AM
 */

#ifndef ANDNET_H
#define	ANDNET_H

#define NET_TYPE_ANDNET "ANDNET"

#include "nn-simulator/main/nets/BDN/LogicalArchitecture.h"
#include "nn-simulator/main/model/Net.h"
#include "nn-simulator/main/model/Input.h"

class ANDnet : public Net {
public:
    ANDnet(int const noInputs);
    virtual ~ANDnet();
protected:
    virtual void createInputVectors();
    virtual void createLayers();
    virtual void createNeurons();
private:
    int noInputs;
    Input *expectedInput;
    Input *necessaryInput;
};

#endif	/* ANDNET_H */

