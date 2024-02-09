#include "bemath/math.h"

#include "gtest/gtest.h"

TEST(Math, Sqrt_One_ReturnOne)
{
	EXPECT_DOUBLE_EQ(BeMath::Sqrt(1), 1);
}

TEST(Math, Sqrt_Zero_ReturnZero)
{
	EXPECT_DOUBLE_EQ(BeMath::Sqrt(0), 0);
}

TEST(Math, Sqr_Sqrt2_Return2)
{
	EXPECT_DOUBLE_EQ(BeMath::Sqrt(BeMath::Sqr(2.0)), 2.0);
}

TEST(Math, Pow25_Pow1Div5_Return2)
{
	EXPECT_DOUBLE_EQ(BeMath::Pow(BeMath::Pow(2, 5), 1.0/5.0), 2.0);
}
