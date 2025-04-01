#include <gtest/gtest.h>
#include "math_capi.h"

// 测试夹具类
class MathCapiTest : public ::testing::Test {
protected:
    void SetUp() override {
        calc = math_create();
    }

    void TearDown() override {
        math_destroy(calc);
    }

    MathHandle calc;
};

// 测试创建和销毁
TEST_F(MathCapiTest, CreateAndDestroy) {
    ASSERT_NE(calc, nullptr);
}

// 测试加法
TEST_F(MathCapiTest, TestAddition) {
    math_add(calc, 10.0);
    EXPECT_FLOAT_EQ(math_get_result(calc), 10.0);

    math_add(calc, 5.0);
    EXPECT_FLOAT_EQ(math_get_result(calc), 15.0);
}

// 测试减法
TEST_F(MathCapiTest, TestSubtraction) {
    math_add(calc, 20.0); // 先设置一个初始值
    math_subtract(calc, 5.0);
    EXPECT_FLOAT_EQ(math_get_result(calc), 15.0);

    math_subtract(calc, 3.0);
    EXPECT_FLOAT_EQ(math_get_result(calc), 12.0);
}

// 测试乘法
TEST_F(MathCapiTest, TestMultiplication) {
    math_add(calc, 4.0); // 先设置一个初始值
    math_multiply(calc, 2.5);
    EXPECT_FLOAT_EQ(math_get_result(calc), 10.0);

    math_multiply(calc, 3.0);
    EXPECT_FLOAT_EQ(math_get_result(calc), 30.0);
}

// 测试复合运算
TEST_F(MathCapiTest, TestCombinedOperations) {
    math_add(calc, 10.0);
    math_multiply(calc, 2.5);
    math_subtract(calc, 5.0);
    EXPECT_FLOAT_EQ(math_get_result(calc), 20.0);
}

// 测试初始状态
TEST_F(MathCapiTest, TestInitialState) {
    EXPECT_FLOAT_EQ(math_get_result(calc), 0.0);
}