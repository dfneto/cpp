#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
        protected:
                const static int baseEP = 51;
	public:
                ScavTrap();
                ScavTrap(const std::string name);
                ScavTrap(const ScavTrap &src);
                ~ScavTrap();

                ScavTrap & operator=(const ScavTrap &rhs);

		void    attack(const std::string& target);
                void    guardGate();
};

#endif
