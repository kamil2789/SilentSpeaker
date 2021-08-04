#include <iostream>
#include "initRepo.h"
#include "asio.hpp"

int main()
{
    asio::error_code ec;
    asio::io_context context;
    std::cout<<"Hello Silent Speaker "<<initFunction(55);
    std::cin.get();
    return 0;
}