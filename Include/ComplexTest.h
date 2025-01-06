#include <gtest/gtest.h>
#include "Complex.h"

// Тесты для конструктора и методов доступа
class ComplexTest : public ::testing::Test {
protected:
    // Общие данные для всех тестов в этом классе
    Complex c1{1.0, 2.0};
    Complex c2{3.0, -4.0};
};

TEST_F(ComplexTest, ConstructorAndAccessors) {
    Complex c_default;
    EXPECT_DOUBLE_EQ(c_default.Real(), 0.0);
    EXPECT_DOUBLE_EQ(c_default.Imag(), 0.0);

    Complex c_real(3.5);
    EXPECT_DOUBLE_EQ(c_real.Real(), 3.5);
    EXPECT_DOUBLE_EQ(c_real.Imag(), 0.0);

    Complex c_full(1.1, -2.2);
    EXPECT_DOUBLE_EQ(c_full.Real(), 1.1);
    EXPECT_DOUBLE_EQ(c_full.Imag(), -2.2);
}

TEST_F(ComplexTest, ArithmeticOperations) {
    EXPECT_EQ(c1 + c2, Complex(4.0, -2.0));
    EXPECT_EQ(c1 - c2, Complex(-2.0, 6.0));
    EXPECT_EQ(c1 * c2, Complex(11.0, 2.0));
    EXPECT_EQ(c1 / c2, Complex(-0.2, 0.4));
}

TEST_F(ComplexTest, CompoundAssignmentOperators) {
    Complex c3 = c1;
    c3 += c2;
    EXPECT_EQ(c3, Complex(4.0, -2.0));

    c3 -= c1;
    EXPECT_EQ(c3, Complex(3.0, -4.0));

    c3 *= c1;
    EXPECT_EQ(c3, Complex(11.0, 2.0));

    c3 /= c2;
    EXPECT_EQ(c3, Complex(1, 2));
}

TEST_F(ComplexTest, ComparisonOperators) {
    EXPECT_TRUE(c1 < Complex(3.0, 4.0));
    EXPECT_FALSE(c1 < Complex(0.5, 1.0));
    EXPECT_TRUE(c1 <= Complex(1.0, 2.0));
    EXPECT_FALSE(c1 > Complex(3.0, 4.0));
    EXPECT_TRUE(c1 != c2);
    EXPECT_FALSE(c1 == c2);
}

TEST_F(ComplexTest, ModulusAndOutput) {
    EXPECT_DOUBLE_EQ(c1.modulus(), std::sqrt(5.0));
    EXPECT_DOUBLE_EQ(c2.modulus(), 5.0);

    std::stringstream ss;
    ss << c1;
    EXPECT_EQ(ss.str(), "1+2i");
}

TEST_F(ComplexTest, DivisionByZero) {
    Complex c_zero(0.0, 0.0);
    EXPECT_THROW(c1 / c_zero, std::runtime_error);
}
