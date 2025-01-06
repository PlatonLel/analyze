#include <gtest/gtest.h>
#include "Linalg.h."

// Тесты для конструктора и базовых операций
class MatrixTest : public ::testing::Test {
protected:
    linalg::Matrix<int> m1{{1, 2}, {3, 4}};
    linalg::Matrix<int> m2{{5, 6}, {7, 8}};
    linalg::Matrix<int> identity = {{1,0},{0,1}};
};

TEST_F(MatrixTest, ConstructorAndInitialization) {
    linalg::Matrix<int> empty_matrix;
    EXPECT_TRUE(empty_matrix.empty());

    linalg::Matrix<int> single_row = {1, 2, 3};
    EXPECT_EQ(single_row.rows(), 1);
    EXPECT_EQ(single_row.columns(), 3);
    EXPECT_EQ(single_row(0, 0), 1);
    EXPECT_EQ(single_row(0, 1), 2);
    EXPECT_EQ(single_row(0, 2), 3);

    linalg::Matrix<int> copied_matrix(m1);
    EXPECT_EQ(copied_matrix, m1);
}

TEST_F(MatrixTest, ArithmeticOperations) {
    EXPECT_EQ(m1 + m2, linalg::Matrix<int>({{6, 8}, {10, 12}}));
    EXPECT_EQ(m1 - m2, linalg::Matrix<int>({{-4, -4}, {-4, -4}}));
    EXPECT_EQ(m1 * m2, linalg::Matrix<int>({{19, 22}, {43, 50}}));
    EXPECT_EQ(m1 * 2, linalg::Matrix<int>({{2, 4}, {6, 8}}));
}

TEST_F(MatrixTest, TransposeAndIdentity) {
    linalg::Matrix<int> transposed = transpose(m1);
    EXPECT_EQ(transposed, linalg::Matrix<int>({{1, 3}, {2, 4}}));

    EXPECT_EQ(identity * m1, m1);
    EXPECT_EQ(m1 * identity, m1);
}

TEST_F(MatrixTest, Determinant) {
    EXPECT_EQ(m1.det(), -2);
    EXPECT_EQ(identity.det(), 1);

    linalg::Matrix<int> zero_matrix({0, 0, 0, 0});
    EXPECT_THROW(zero_matrix.det(), linalg::Wrong_matrix_size);
}

TEST_F(MatrixTest, Inverse) {
    linalg::Matrix<int> singular{{1, 2}, {2, 4}};
    EXPECT_THROW(invert(singular), linalg::Singular_matrix);

    linalg::Matrix<double> invertible{{4, 7}, {2, 6}};
    EXPECT_EQ(invert(invertible), linalg::Matrix<double>({{0.6, -0.7}, {-0.2, 0.4}}));
}

TEST_F(MatrixTest, ResizeAndClear) {
    linalg::Matrix<int> resizable = m1;
    resizable.reshape(1, 4);
    EXPECT_EQ(resizable, linalg::Matrix<int>({{1, 2, 3, 4}}));

    resizable.clear();
    EXPECT_TRUE(resizable.empty());
}

TEST_F(MatrixTest, IteratorsAndAccess) {
    std::vector<int> elements(m1.begin(), m1.end());
    EXPECT_EQ(elements, std::vector<int>({1, 2, 3, 4}));

    EXPECT_EQ(m1(0, 1), 2);
    EXPECT_THROW(m1(3, 3), linalg::Wrong_matrix_size);
}
