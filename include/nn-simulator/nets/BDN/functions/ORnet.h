/* 
 * File:   ORnet.h
 * Author: Will
 *
 * Created on 09 June 2011, 18:06
 */

#ifndef ORNET_H
#define	ORNET_H

#include "../LogicalArchitecture.h"
#include "../../../model/Net.h"
#include "../../../model/Input.h"

class ORnet : public Net {
public:
    ORnet(int noInputs);
    virtual ~ORnet();
protected:
    virtual void createInputVectors();
    virtual void createLayers();
    virtual void createNeurons();
private:
    Input *expectedInput;
    Input *necessaryInput;
};

#endif	/* ORNET_H */

