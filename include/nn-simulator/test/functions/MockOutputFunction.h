/* 
 * File:   MockOutputFunction.h
 * Author: will
 *
 * Created on 02 July, 2011, 11:26 AM
 */

#ifndef MOCKOUTPUTFUNCTION_H
#define	MOCKOUTPUTFUNCTION_H

#include "gmock/gmock.h"
#include "nn-simulator/main/functions/OutputFunction.h"

class MockOutputFunction : public OutputFunction {
 public:
  MOCK_CONST_METHOD1(function,
      Output(float const activation));
};

#endif
