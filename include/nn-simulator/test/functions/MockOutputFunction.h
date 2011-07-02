/* 
 * File:   MockOutputFunction.h
 * Author: will
 *
 * Created on 02 July, 2011, 11:26 AM
 */

#include "nn-simulator/main/functions/OutputFunction.h"
#include "gmock/gmock.h"

class MockOutputFunction : public OutputFunction {
 public:
  MOCK_METHOD1(function,
      Output*(float activation));
};
