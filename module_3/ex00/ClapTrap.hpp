#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string		name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap();
		
		ClapTrap & operator=(const ClapTrap &rhs);
		
		void	attack(const std::string& target); //TODO: pq & e não somente uma string?
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printInfo();
};


#endif
