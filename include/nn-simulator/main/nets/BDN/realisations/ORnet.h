/* 
 * File:   ORnet.h
 * Author: Will
 *
 * Created on 09 June 2011, 18:06
 */

#ifndef ORNET_H
#define	ORNET_H

#define NET_TYPE_ORNET "ORNET"

#include "nn-simulator/main/nets/BDN/LogicalArchitecture.h"
#include "nn-simulator/main/model/Net.h"
#include "nn-simulator/main/model/Input.h"

class ORnet : public Net {
public:
    ORnet(int const noInputs);
    virtual ~ORnet();
protected:
    virtual void createInputVectors();
    virtual void createLayers();
    virtual void createNeurons();
private:
    int noInputs;
    Input *expectedInput;
    Input *necessaryInput;
};

#endif	/* ORNET_H */

