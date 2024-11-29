#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    name = "DefaultDiamond";
    ClapTrap::name = name +  "_clap_name";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::baseEP;
    attackDamage = FragTrap::baseAttack;
    std::cout << "DiamondTrap Default Constructor (name: " << name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string str) {
    this->name = str;
    this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::baseEP;
	this->attackDamage = FragTrap::baseAttack;
    std::cout << "Creating " << name << " diamond trap (diamond named constructor)" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

//In the copy constructor, explicit base class copying is required to ensure 
//the entire derived object (including its base class subobjects) is correctly duplicated, because
//the compiler cannot assume how to handle the copying of base class subobjects. Should it:
//Call the copy constructor of the base class?
//Call the default constructor of the base class and copy members manually?the compiler cannot assume how to handle the copying of base class subobjects. Should it:
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
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

void DiamondTrap::setName(std::string newName) {
    std::cout << "My old name: " << this->name << std::endl;
    this->name = newName;
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
