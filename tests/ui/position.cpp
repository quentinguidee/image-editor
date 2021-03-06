#include "../../src/ui/position.hpp"

#include <gtest/gtest.h>

TEST(Position1DTest, operatorAdd)
{
    EXPECT_EQ(Position1D(50) + Position1D(30), Position1D(80));
    EXPECT_EQ(Position1D(50) + Position1D(-30), Position1D(20));
}

TEST(Position1DTest, operatorAppend)
{
    EXPECT_EQ(Position1D(50) += Position1D(30), Position1D(80));
    EXPECT_EQ(Position1D(50) += Position1D(-30), Position1D(20));
}

TEST(Position1DTest, operatorGreater)
{
    EXPECT_TRUE(Position1D(50) > Position1D(30));
    EXPECT_FALSE(Position1D(30) > Position1D(30));
    EXPECT_FALSE(Position1D(-20) > Position1D(-10));
    EXPECT_TRUE(Position1D(10) > Position1D(0));
}

TEST(Position1DTest, operatorLess)
{
    EXPECT_TRUE(Position1D(30) < Position1D(50));
    EXPECT_FALSE(Position1D(30) < Position1D(30));
    EXPECT_FALSE(Position1D(-10) < Position1D(-20));
    EXPECT_TRUE(Position1D(0) < Position1D(10));
}

TEST(Position1DTest, operatorGreaterOrEqual)
{
    EXPECT_TRUE(Position1D(50) >= Position1D(30));
    EXPECT_TRUE(Position1D(30) >= Position1D(30));
    EXPECT_FALSE(Position1D(-20) >= Position1D(-10));
    EXPECT_TRUE(Position1D(10) >= Position1D(0));
}

TEST(Position1DTest, operatorLessOrEqual)
{
    EXPECT_TRUE(Position1D(30) <= Position1D(50));
    EXPECT_TRUE(Position1D(30) <= Position1D(30));
    EXPECT_FALSE(Position1D(-10) <= Position1D(-20));
    EXPECT_TRUE(Position1D(0) <= Position1D(10));
}

TEST(PositionTest, operatorBrackets)
{
    Position position = Position(30, 50);
    EXPECT_EQ(position[0].x, 30);
    EXPECT_EQ(position[1].x, 50);
}
