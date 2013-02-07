/*
 * File:   NetTest.cpp
 * Author: Will
 *
 * Created on 02 July, 21:32
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Net.h"
#include "nn-simulator/test/model/MockArchitecture.h"
#include "nn-simulator/test/model/MockLayer.h"

#define TEST_NET_TYPE "test net type"

using ::testing::Return;
using ::testing::_;

namespace {

    class NetTest : public ::testing::Test {
    protected:

        NetTest() {
            noLayers = 1;
            noInputs = 1;
            architectureMock = new MockArchitecture();
            net = new Net(auto_ptr<Architecture > (architectureMock),
                    noLayers, noInputs, TEST_NET_TYPE);
        }

        virtual ~NetTest() {
            delete net;
        }
        int noLayers;
        int noInputs;
        MockArchitecture *architectureMock;
        Net *net;
        char *netType;
    };

    /*
     * Tests whether the throws exceptions correctly.
     *
     */
    TEST_F(NetTest, ConstructorExceptionTest) {
        EXPECT_THROW(
                new Net(auto_ptr<Architecture > (NULL),
                noLayers, noInputs, TEST_NET_TYPE),
                IllegalArgumentException);
        EXPECT_THROW(
                new Net(auto_ptr<Architecture > (new MockArchitecture()),
                3, noInputs, TEST_NET_TYPE),
                UnsupportedConfigurationException);
    }

    /*
     * Tests whether the number of layers is returned correctly.
     *
     */
    TEST_F(NetTest, GetNoLayersTest) {
        EXPECT_EQ(noLayers, net->getNoLayers());
    }

    /*
     * Tests whether the net's type is returned correctly.
     *
     */
    TEST_F(NetTest, GetNetTypeTest) {
        EXPECT_EQ(TEST_NET_TYPE, net->getNetType());
    }

    /*
     * Tests whether the layer getter and setter work correctly.
     *
     */
    TEST_F(NetTest, LayerTest) {
        MockLayer *layerMock = new MockLayer();
        net->setLayer(0, auto_ptr<Layer > (layerMock));
        EXPECT_EQ(layerMock, net->getLayer(0));
    }

    /*
     * Tests whether the architecture is returned correctly.
     *
     */
    TEST_F(NetTest, GetArchitectureTest) {
        EXPECT_EQ(architectureMock, net->getArchitecture());
    }

    /*
     * Tests whether the number of inputs is returned correctly.
     *
     */
    TEST_F(NetTest, GetNoInputsTest) {
        EXPECT_EQ(noInputs, net->getNoInputs());
    }

    /*
     * Tests whether an input is processed correctly.
     *
     */
    TEST_F(NetTest, ProcessInputTest) {
        EXPECT_THROW(net->processInput(Input(2)),
                IncorrectInputException);

        Input input = Input(1);
        float expected = 0.34f;
        input.setValue(0, expected);

        MockLayer *layerMock = new MockLayer();
        EXPECT_CALL((*layerMock), processInput(_))
                .WillOnce(Return(input));
        net->setLayer(0, auto_ptr<Layer > (layerMock));

        Output result = net->processInput(input);
        EXPECT_EQ(expected, result.getValue());
    }
}
