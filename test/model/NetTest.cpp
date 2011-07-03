/*
 * File:   NetTest.cpp
 * Author: Will
 *
 * Created on 02 July, 21:32
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Net.h"

namespace {

    class NetTest : public ::testing::Test {
    protected:
        NetTest(){
            
        }
        virtual ~NetTest(){
            
        }
//        Architecture *architecture;
//        Net *net;
    };

    /*
     * Tests whether the maximum number of layers is returned correctly.
     *
     */
    TEST_F(NetTest, GetMaxLayersTest) {
//        EXPECT_EQ(noLayers, architecture->getMaxLayers());
    }
}
