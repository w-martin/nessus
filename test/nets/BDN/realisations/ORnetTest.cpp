/* 
 * File:   ORnetTest.cpp
 * Author: will
 * 
 * Created on July 14, 2011, 6:29 PM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/nets/BDN/realisations/ORnet.h"
#include "nn-simulator/main/model/Input.h"
#include "nn-simulator/main/nets/BDN/LogicalArchitecture.h"
#include "nn-simulator/main/nets/BDN/BDN.h"

namespace {

    class ORnetTest : public ::testing::Test {
    protected:

        ORnetTest() {
            noInputs = 1;
            net = new ORnet(noInputs);
        }

        virtual ~ORnetTest() {
            delete net;
        }

        int noInputs;
        ORnet *net;
    };

    /*
     * Tests whether the parent constructor is called
     * correctly.
     *
     */
    TEST_F(ORnetTest, ConstructorTest) {
        EXPECT_EQ(noInputs, net->getNoInputs());
        EXPECT_EQ(1, net->getNoLayers());
        EXPECT_EQ(0, strcmp(NET_TYPE_ORNET, net->getNetType()));
        LogicalArchitecture *la = (LogicalArchitecture*)
                net->getArchitecture();
        Layer *l = net->getLayer(0);
        BDN *bdn = (BDN*) l->getNeuron(0);
    }

    /*
     * Tests whether the function works correctly.
     *
     */
    TEST_F(ORnetTest, FunctionTest) {
        Input trueInput = Input(noInputs);
        for (int i = 0; i < noInputs; i++) {
            trueInput.setValue(i, 1.0f);
        }
        EXPECT_EQ(1.0f, net->processInput(trueInput).getValue());

        Input falseInput = Input(noInputs);
        for (int i = 0; i < noInputs; i++) {
            falseInput.setValue(i, 0.0f);
        }
        EXPECT_EQ(0.0f, net->processInput(falseInput).getValue());
    }
}
