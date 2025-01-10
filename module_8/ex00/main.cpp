#include "Easyfind.hpp"

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(42);
	vec.push_back(30);

	try {
		std::cout << easyfind(vec, 130) << std::endl;
	} catch (NotFoundException e) {
		std::cout << "Exception caugh: " << e.what() << std::endl;
	}

	try {
		std::cout << "Element " << easyfind(vec, 42) << "find!" << std::endl;
	} catch (NotFoundException e) {
		std::cout << "Exception caugh: " << e.what() << std::endl;
	}

	return (0);
}
