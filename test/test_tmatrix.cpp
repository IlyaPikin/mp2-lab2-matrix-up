#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int> m(TVector<int>::max_size + 1ull));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(5);

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> a(5);
    a[1][1] = 1;
    TMatrix<int> b(a);
    EXPECT_EQ(b, a);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> a(5);
    a[1][1] = 1;
    TMatrix<int> b(a);
    b[1][1] = 2;
    EXPECT_NE(b, a);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> a(5);
    EXPECT_EQ(a.getSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> a(5);
    a[0].setElement(4, 80);
    EXPECT_EQ(80, a[0].getElement(4));
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> a(5);
    ASSERT_ANY_THROW(a[0].setElement(-5, 1));
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> a(5);
    ASSERT_ANY_THROW(a[0].setElement(5, 5));
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> a(5);
    a[0][0] = 1;
    ASSERT_NO_THROW(a = a);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> a(5);
    a[0][0] = 1;
    TMatrix<int> b(5);
    ASSERT_NO_THROW(b = a);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> a(5);
    TMatrix<int> b(2);
    b = a;
    EXPECT_EQ(b.getSize(), 5); 
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> a(5);
    a[0][0] = 1;
    TMatrix<int> b(2);
    b = a;
    EXPECT_EQ(b[0][0], 1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> a(5);
    TMatrix<int> b(a);
    EXPECT_EQ(a, b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> a(5);
    EXPECT_EQ(a, a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> a(5);
    TMatrix<int> b(6);
    EXPECT_NE(a, b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> a(5), b(5);
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
            b[i][j] = 1;
        }
    }
    ASSERT_NO_THROW(a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> a(5);
    TMatrix<int> b(2);
    ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> a(5), b(5);
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = i; j < 5; j++)
        {
            a[i][j] = 2;
            b[i][j] = 1;
        }
    }
    ASSERT_NO_THROW(a - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> a(5);
    TMatrix<int> b(2);
    ASSERT_ANY_THROW(a - b);
}
