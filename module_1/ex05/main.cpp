#include <iostream>
#include <string>
#include "Harl.hpp"

static char *to_lower(char *str)
{
    char *head;

    head = str;
    while (*str)
    {
        *str = std::tolower(*str);
        str++;      
    }
    return head;
}

int main(int argc, char *argv[])
{
    Harl harl;
    
    if (argc != 2)
        return std::cout << "Wrong number of argments\nUsage: ./harlFilter [LEVEL]" << std::endl, 1;
    harl.complain(to_lower(argv[1]));
	return 0;
}