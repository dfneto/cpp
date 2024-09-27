#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    std::string _name;
    Weapon      *_weapon;  // Pointer to Weapon (so it can be nullptr)

    public:
        HumanB(std::string name);
		void    attack();
        void    setWeapon(Weapon &weapon);
};

#endif
