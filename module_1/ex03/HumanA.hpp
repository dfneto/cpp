#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    std::string _name;
    Weapon &_weapon;

    public:
        HumanA(std::string name, Weapon &weapon);
		void    attack();
};

#endif
// É &weapon e não weapon porque preciso passar uma referência a arma e não uma cópia da arma (sem &).
// Se passasse uma cópia
//      Weapon club = Weapon("crude spiked club");
//      std::cout << "The memory address of club is " << &club << std::endl;
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// Eu não seria capaz de setar outro tipo de arma (club.setType("some other type of club")) no main,
// e sim somento no construtor (HumanA bob("Bob", club)).
