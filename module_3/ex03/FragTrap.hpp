#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

//virtual para que a classe que herde de FlagTrap e de ClapTrap
//ao mesmo tempo tenha somente uma cópia dos atributos
class FragTrap : virtual public ClapTrap {
        
        //Agora tenho que criar atributos para que 
        //DiamondClass possa refenciar esses valores
        protected:
                //Para definir um valor aqui deve ser static e então eu seto o valor 
                //ora do hpp, por exemplo em FragTrap.cpp (int FragTrap::baseAttack = 100)
                //Se aqui for const tenho que setar o valor e não posso alterá-lo depois
		const static int        baseAttack = 999;
	public:
                FragTrap();
                FragTrap(const std::string name);
                FragTrap(const FragTrap &src);
                ~FragTrap();

                FragTrap & operator=(const FragTrap &rhs);

		void highFivesGuys();
};

#endif
