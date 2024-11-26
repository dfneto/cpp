#include "ClapTrap.hpp"

int main()
{
	std::cout << ">> Create a ClapTrap object with default and string constructor" << std::endl << std::endl;
	ClapTrap claptrap1;
	ClapTrap claptrap2("CT2");

	std::cout << std::endl << ">> Test attack, takeDamage, and beRepaired functionalities" << std::endl << std::endl;
	claptrap1.attack("Target1");
	claptrap2.attack("Target2");

	claptrap1.takeDamage(5);
	claptrap2.takeDamage(3);

	claptrap1.beRepaired(2);
	claptrap2.beRepaired(4);

	std::cout << std::endl << ">> Test copy constructor and copy assignment operator" << std::endl << std::endl;
	ClapTrap claptrap3;
	claptrap3 = claptrap1;
	ClapTrap claptrap4(claptrap2);

	claptrap3.attack("Target3");
	claptrap4.attack("Target4");

	std::cout << "\n>> The Life and Death of claptrap4\n\n";
	claptrap4.printInfo();
	std::cout << std::endl;
	claptrap4.takeDamage(100);
	std::cout << std::endl;
	claptrap4.takeDamage(10);
	std::cout << std::endl;
	claptrap4.beRepaired(20);
	std::cout << std::endl;
	claptrap4.attack("Enemy");
	std::cout << std::endl;
	claptrap4.printInfo();

	return 0;
}
