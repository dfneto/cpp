#include <iostream>

int main(int argc, char **argv) {
    
    if (argc == 1)
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    	return (0);
	}
    int i = 0;
	argv++;
    while (*argv)
    {
		while ((*argv)[i])
        {
			std::cout << (char)std::toupper((*argv)[i]);
			i++;
		}
		argv++;
		i = 0;
    }
	std::cout << std::endl;
	return (0);
}
