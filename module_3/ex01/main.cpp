#include "ScavTrap.hpp"

// cuando hacemos ScavTrap scav4 = scav1; es lo mismo que hacer
// ScavTrap scav3(scav2); pero diferente de hacer esto:
// ScavTrap scav4;
// scav4 = scav1;

int main()
{
	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	ScavTrap scav1;
	// scav1.printInfo();
	std::cout << std::endl << "-----------------" << std::endl << std::endl;

	ScavTrap scav2("Washington Luis");
	// scav2.printInfo();
	std::cout << std::endl << "3-----------------" << std::endl << std::endl;

	ScavTrap scav3(scav2);
	// scav3.printInfo();
	std::cout << std::endl << "4-----------------" << std::endl << std::endl;

	ScavTrap scav4 = scav1;
	// scav4.printInfo();
	// std::cout << std::endl << "-----------------" << std::endl << std::endl;

	// scav4.attack("someone");
	// scav4.printInfo();
	// std::cout << std::endl << "-----------------" << std::endl << std::endl;

	// scav1.guardGate();
	std::cout << std::endl << "5-----------------" << std::endl << std::endl;
	ScavTrap scav5;
	scav5 = scav1;

	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	
	return 0;
}
