/* 
 * File:   VectorTest.cpp
 * Author: will
 * 
 * Created on June 30, 2011, 7:58 AM
 */

#include "gtest/gtest.h"
#include "nn-simulator/main/model/Vector.h"
#include "nn-simulator/main/model/exceptions/EmptyVectorException.h"
#include "nn-simulator/main/util/exceptions/OutOfBoundsException.h"

namespace {

    class VectorTest : public ::testing::Test {
    protected:

        VectorTest() {
            size = 2;
            vector = new Vector(size);
        }

        virtual ~VectorTest() {
            delete vector;
        }
        int size;
        Vector *vector;
    };

    /**
     * Tests whether an exception is thrown by the constructor.
     * 
     */
    TEST_F(VectorTest, ConstructorExceptionTest) {
        ASSERT_THROW(new Vector(0), EmptyVectorException*);
    }

    /**
     * Tests whether the <code>Vector</code> object is initialized
     * correctly.
     * 
     */
    TEST_F(VectorTest, InitializationTest) {
        EXPECT_EQ(size, vector->getSize());
        for (int i = 0; i < size; i++) {
            EXPECT_EQ(1.0f, vector->getValue(i));
        }
    }

    /*
     * Tests whether the getValue method throws an exception.
     * 
     */
    TEST_F(VectorTest, GetValueExceptionTest) {
        ASSERT_THROW(vector->getValue(size + 1), OutOfBoundsException*);
    }

    /*
     * Tests whether the setValue method throws an exception.
     * 
     */
    TEST_F(VectorTest, SetValueExceptionTest) {
        ASSERT_THROW(vector->setValue(size + 1, 0.0f),
                OutOfBoundsException*);
    }

    /*
     * Tests whether the value getter and setter work correctly.
     * 
     */
    TEST_F(VectorTest, ValueTest) {
        int max = 10;
        for (int i = 0; i < max; i++) {
            vector->setValue(0, i + 0.5f);
            ASSERT_EQ(i + 0.5f, vector->getValue(0));
        }
    }

    /*
     * Tests whether the getSize method works correctly.
     * 
     */
    TEST_F(VectorTest, GetSizeTest) {
        int max = 10;
        for (int i = 1; i < 10; i++) {
            Vector *tmp = new Vector(i);
            ASSERT_EQ(i, tmp->getSize());
            delete tmp;
        }
    }
}