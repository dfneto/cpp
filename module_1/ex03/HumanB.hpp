#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    std::string name;
    Weapon weapon;

    public:
        HumanB(std::string);
		void    attack();
        void    setWeapon(Weapon);
};

#endif