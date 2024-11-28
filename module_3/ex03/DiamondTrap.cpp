#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    name = "DefaultDiamond";
    ClapTrap::name = name +  "_clap_name";
    hitPoints = FragTrap::baseHP;
    energyPoints = ScavTrap::baseEP;
    attackDamage = FragTrap::baseAttack;
    std::cout << "DiamondTrap Default Constructor (name: " << name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string str) {
    this->name = str;
    this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::baseHP;
	this->energyPoints = ScavTrap::baseEP;
	this->attackDamage = FragTrap::baseAttack;
    std::cout << "Creating " << name << " diamond trap (diamond named constructor)" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) {
    *this = src; //Isso chama o operator=
    std::cout << "Making a copy of " << name << " diamond trap (diamond copy constructor)" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
    if (this != &rhs) {
        this->name = rhs.name + "DefaultDiamond_assignmentDiamondCopy";
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
    }
    std::cout << "Creating " << name << " (diamond copy assignment constructor)" << std::endl;
    return *this;
}

void	DiamondTrap::attack(const std::string& target) {
    this->ScavTrap::attack(target);
}

void DiamondTrap::setName(std::string name) {
    std::cout << "My old name: " << this->name << std::endl;
    this->name = name;
    std::cout << "My new name: " << this->name << std::endl;
}

void DiamondTrap::setHP(int newHP) {
    this->hitPoints = newHP;
}

void DiamondTrap::whoAmI() {
    std::cout << "My clap name: " << this->ClapTrap::name << std::endl;
    std::cout << "My diamond name: " << this->name << std::endl;
}

void DiamondTrap::printInfo() {
	std::cout << "Hello from Diamond!\nI am " << name << "." << std::endl;
	std::cout << "My stats:\nHit points: " << hitPoints << "\nEnergy points: " << energyPoints << "\nAttack damage: " << attackDamage << std::endl;
}
