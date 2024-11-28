#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    name = "DefaultDiamond";
    ClapTrap::name = name +  "_clap_name"; //TODO; como que diamond tem claptrap.name??
    hitPoints = FragTrap::baseHP;
    energyPoints = ScavTrap::baseEP;
    attackDamage = FragTrap::baseAttack;
    std::cout << "DiamondTrap Default Constructor - " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string value) {
    this->name = value;
    this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::baseHP;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::baseAttack;
    std::cout << "Creating " << name << " diamond trap (diamond named constructor)" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) {
    std::cout << "Making a copy of " << name << " clap trap (copy constructor)" << std::endl;
    *this = src;
}

// DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
//     if (this != &rhs) {
//         // *this = rhs; Aqui o compilador não saberia tratar isso e por isso tenho que fazer as associações abaixo
//         this->name = rhs.name + "_assignmentCopy";
// 		this->hitPoints = rhs.hitPoints;
// 		this->energyPoints = rhs.energyPoints;
// 		this->attackDamage = rhs.attackDamage;
//     }
//     std::cout << "Creating " << name << " (copy assignment constructor)" << std::endl;
//     return *this;
// }

// void	DiamondTrap::attack(const std::string& target) {
//     if (!hitPoints || !energyPoints) {
//         std::cout << "DiamondTrap " << name << "can't attack :/" << std::endl;
//         return ;
//     }
//     energyPoints--;
//     std::cout << "DiamondTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
// }

