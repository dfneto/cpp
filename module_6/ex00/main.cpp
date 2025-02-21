#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << R << "Error: " << E
			<< (ac > 1 ? "you have more than one argument" : "invalid argument")
			<< std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
