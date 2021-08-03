#include <iostream>
#include "gtest\gtest.h"

int main()
{
    testing::InitGoogleTest(&argc, argv);
	auto result = RUN_ALL_TESTS();

    return 0;
}