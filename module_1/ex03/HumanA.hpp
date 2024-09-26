#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    std::string name;
    Weapon weapon;

    public:
        HumanA(std::string, Weapon);
		void    attack();
};

#endif

//TODO: o destrutor eh necessario para limpar os leaks?