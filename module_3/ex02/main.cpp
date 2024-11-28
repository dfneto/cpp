#include "FragTrap.hpp"

int main()
{
	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	FragTrap frag1;
	frag1.printInfo();
	std::cout << std::endl << "-----------------" << std::endl << std::endl;

	FragTrap frag2("Washington Luis");
	frag2.printInfo();
	std::cout << std::endl << "-----------------" << std::endl << std::endl;

	FragTrap frag3(frag2);
	frag3.printInfo();
	std::cout << std::endl << "-----------------" << std::endl << std::endl;

	FragTrap frag4 = frag1;
	frag4.printInfo();
	std::cout << std::endl << "-----------------" << std::endl << std::endl;

	frag4.attack("someone");
	frag4.printInfo();
	std::cout << std::endl << "-----------------" << std::endl << std::endl;

	frag1.highFivesGuys();

	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	
	return 0;
}
