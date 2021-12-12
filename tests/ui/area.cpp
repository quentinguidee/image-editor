#include "../../src/ui/area.hpp"

#include <gtest/gtest.h>

TEST(AreaTest, contains)
{
    Area area = Area(Position(30, 50), Size(10, 20));
    EXPECT_TRUE(area.contains({40, 70}));
    EXPECT_TRUE(area.contains({30, 50}));
    EXPECT_TRUE(area.contains({40, 50}));
    EXPECT_TRUE(area.contains({30, 70}));
    EXPECT_FALSE(area.contains({29, 49}));
    EXPECT_FALSE(area.contains({29, 60}));
    EXPECT_FALSE(area.contains({35, 80}));
    EXPECT_FALSE(area.contains({42, 80}));
}
