#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl harl;
    
    if (argc != 2)
        return std::cout << "Wrong number of argments\nUsage: ./harl [LEVEL]" << std::endl, 1;
    harl.complain(argv[1]);
	return 0;
}