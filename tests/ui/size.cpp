#include "../../src/ui/size.hpp"

#include <gtest/gtest.h>

TEST(Size1DTest, operatorAdd)
{
    EXPECT_EQ(Size1D(50) + Size1D(30), Size1D(80));
    EXPECT_EQ(Size1D(50) + Size1D(-30), Size1D(20));
}

TEST(Size1DTest, operatorAppend)
{
    EXPECT_EQ(Size1D(50) += Size1D(30), Size1D(80));
    EXPECT_EQ(Size1D(50) += Size1D(-30), Size1D(20));
}

TEST(Size1DTest, operatorGreater)
{
    EXPECT_TRUE(Size1D(50) > Size1D(30));
    EXPECT_FALSE(Size1D(30) > Size1D(30));
    EXPECT_FALSE(Size1D(-20) > Size1D(-10));
    EXPECT_TRUE(Size1D(10) > Size1D(0));
}

TEST(Size1DTest, operatorLess)
{
    EXPECT_TRUE(Size1D(30) < Size1D(50));
    EXPECT_FALSE(Size1D(30) < Size1D(30));
    EXPECT_FALSE(Size1D(-10) < Size1D(-20));
    EXPECT_TRUE(Size1D(0) < Size1D(10));
}

TEST(SizeTest, operatorBrackets)
{
    Size size = Size(30, 50);
    EXPECT_EQ(size[0].width, 30);
    EXPECT_EQ(size[1].width, 50);
}
