#include "DiamondTrap.hpp"

int main()
{
	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	DiamondTrap d1;
	d1.printInfo();

	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	DiamondTrap d2("Pepe");
	d2.printInfo();

	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	DiamondTrap d3(d1);
	d3.setName("Copy_of_d1"); 
	d3.setHP(42);
	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	d3.printInfo();
	d3.attack("Someone");
	d3.whoAmI();

	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	DiamondTrap d4 = d3;
	d4.printInfo();
	
	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	
	return 0;
}
