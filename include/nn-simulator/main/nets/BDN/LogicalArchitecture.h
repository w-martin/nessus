/* 
 * File:   LogicalArchitecture.h
 * Author: Will
 *
 * Created on 09 June 2011, 09:45
 */

#ifndef LOGICALARCHITECTURE_H
#define	LOGICALARCHITECTURE_H

#include "nn-simulator/main/model/Architecture.h"

/**
 * Architecture implementation which models logical functions.
 * 
 */
class LogicalArchitecture : public Architecture {
public:
    LogicalArchitecture();
    virtual ~LogicalArchitecture();
};

#endif	/* LOGICALARCHITECTURE_H */

