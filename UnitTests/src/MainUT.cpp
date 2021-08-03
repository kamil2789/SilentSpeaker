#include <iostream>
#include "gtest\gtest.h"

int main()
{
    testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();

    return 0;
}