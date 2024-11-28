#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string		name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string name); //TODO: parei aqui
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap();
		
		// DiamondTrap & operator=(const DiamondTrap &rhs);
		
		// void	attack(const std::string& target);
		// void	whoAmI();
};


#endif
