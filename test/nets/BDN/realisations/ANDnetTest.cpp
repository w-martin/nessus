/* 
 * File:   ANDnetTest.cpp
 * Author: will
 * 
 * Created on July 24, 2011, 9:25 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/nets/BDN/realisations/ANDnet.h"
#include "nn-simulator/main/model/Input.h"
#include "nn-simulator/main/nets/BDN/LogicalArchitecture.h"
#include "nn-simulator/main/nets/BDN/BDN.h"

namespace {

    class ANDnetTest : public ::testing::Test {
    protected:

        ANDnetTest() {
            noInputs = 1;
            net = new ANDnet(noInputs);
        }

        virtual ~ANDnetTest() {
            delete net;
        }

        int noInputs;
        ANDnet *net;
    };

    /*
     * Tests whether the parent constructor is called
     * correctly.
     *
     */
    TEST_F(ANDnetTest, ConstructorTest) {
        EXPECT_EQ(noInputs, net->getNoInputs());
        EXPECT_EQ(1, net->getNoLayers());
        EXPECT_EQ(0, strcmp(NET_TYPE_ANDNET, net->getNetType()));
        LogicalArchitecture *la = (LogicalArchitecture*)
                net->getArchitecture();
        Layer *l = net->getLayer(0);
        BDN *bdn = (BDN*) l->getNeuron(0);
    }

    /*
     * Tests whether the function works correctly.
     *
     */
    TEST_F(ANDnetTest, FunctionTest) {
        Input trueInput = Input(noInputs);
        for (int i = 0; i < noInputs; i++) {
            trueInput.setValue(i, 1.0f);
        }
        EXPECT_EQ(1.0f, net->processInput(trueInput).getValue());

        Input falseInput = Input(noInputs);
        for (int i = 0; i < noInputs; i++) {
            falseInput.setValue(i, (i == 0) ? 1.0f : 0.0f);
        }
        EXPECT_EQ(0.0f, net->processInput(falseInput).getValue());
    }
}
