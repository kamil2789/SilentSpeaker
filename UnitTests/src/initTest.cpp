#include "initRepo.h"
#include "gtest\gtest.h"

TEST(initTest, InitRepo)
{
    EXPECT_EQ(30, initFunction(10));
}