#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

//virtual para que a classe que herde de FlagTrap e de ClapTrap
//ao mesmo tempo tenha somente uma cópia dos atributos
class FragTrap : virtual public ClapTrap {
        
        //Agora tenho que criar atributos para que 
        //DiamondClass possa refenciar esses valores
        protected:
                const static int        baseHP = 100; //TODO: pq precisa ser const static?
		const static int        baseAttack = 30;
	public:
                FragTrap();
                FragTrap(const std::string name);
                FragTrap(const FragTrap &src);
                ~FragTrap();

                FragTrap & operator=(const FragTrap &rhs);

		void highFivesGuys();
};

#endif
