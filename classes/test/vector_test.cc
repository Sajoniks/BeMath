#include "bemath/classes.h"
#include "gtest/gtest.h"

TEST(Vector, Dot_CodirectionalVectors_ReturnPositive)
{
	BeMath::Vector3f v1;
	BeMath::Vector3f v2;
	v1.z = 1;
	v2.z = 1;
	EXPECT_GE(BeMath::Dot(v1, v2), 0.f);
}

TEST(Vector, Dot_PerpendicularVectors_ReturnZero)
{
	BeMath::Vector3f v1;
	BeMath::Vector3f v2;
	v1.z = 1;
	v2.x = 1;
	EXPECT_EQ(BeMath::Dot(v1, v2), 0);
}

TEST(Vector, Dot_OppositelyDirectedVectors_ReturnNegative)
{
	BeMath::Vector3f v1;
	BeMath::Vector3f v2;
	v1.z = 1;
	v2.z = -1;
	EXPECT_LE(BeMath::Dot(v1, v2), 0.f);
}

TEST(Vector, Size_NormalizedVector_EqualsOne)
{
	{
		const BeMath::Vector3f v1{ -1, 0, 0 };
		EXPECT_FLOAT_EQ(v1.size(), 1.f);
	}

	{
		const BeMath::Vector3f v1{ 1, 0, 0 };
		EXPECT_FLOAT_EQ(v1.size(), 1.f);
	}

	{
		const BeMath::Vector3f v1{ 0, 1, 0 };
		EXPECT_FLOAT_EQ(v1.size(), 1.f);
	}

	{
		const BeMath::Vector3f v1{ 0, -1, 0 };
		EXPECT_FLOAT_EQ(v1.size(), 1.f);
	}

	{
		const BeMath::Vector3f v1{ 0, 0, 1 };
		EXPECT_FLOAT_EQ(v1.size(), 1.f);
	}

	{
		const BeMath::Vector3f v1{ 0, 0, -1 };
		EXPECT_FLOAT_EQ(v1.size(), 1.f);
	}

	{
		const BeMath::Vector3f v = BeMath::Normalize(BeMath::Vector3f{ 100, 200, 300 });
		EXPECT_FLOAT_EQ(v.size(),	1.f);
	}

	{
		const BeMath::Vector3f v = BeMath::Normalize(BeMath::Vector3f{ -100, 200, 300 });
		EXPECT_FLOAT_EQ(v.size(),	1.f);
	}

	{
		const BeMath::Vector3f v = BeMath::Normalize(BeMath::Vector3f{ 100, -200, 300 });
		EXPECT_FLOAT_EQ(v.size(),	1.f);
	}

	{
		const BeMath::Vector3f v = BeMath::Normalize(BeMath::Vector3f{ 100, 200, -300 });
		EXPECT_FLOAT_EQ(v.size(),	1.f);
	}

	{
		const BeMath::Vector3f v = BeMath::Normalize(BeMath::Vector3f{ -100, -200, -300 });
		EXPECT_FLOAT_EQ(v.size(),	1.f);
	}
}

TEST(Vector, Cross_IsOrtogonal)
{
	BeMath::Vector3f a{ 1, 2, 3};
	BeMath::Vector3f b{ 1, -2, 5 };
	BeMath::Vector3f r = Cross(a, b);

	EXPECT_FLOAT_EQ(BeMath::Dot(a, r), 0.f);
	EXPECT_FLOAT_EQ(BeMath::Dot(b, r), 0.f);
}

TEST(Vector, Cross_RightHandDirectionTest_IsGreaterThanZero)
{
	BeMath::Vector3f a{ 5, 0, 0};
	BeMath::Vector3f b{ 0, 3, 0 };
	BeMath::Vector3f r = Cross(a, b);

	EXPECT_GE(r.z, 0);
}

TEST(Vector, Cross_RightHandDirectionTest_IsLessThanZero)
{
	BeMath::Vector3f a{ 5, 0, 0};
	BeMath::Vector3f b{ 0, -3, 0 };
	BeMath::Vector3f r = Cross(a, b);

	EXPECT_LE(r.z, 0);
}