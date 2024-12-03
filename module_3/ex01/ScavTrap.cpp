#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Scav default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Creating " << name << " scav trap (scav named constructor)" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    std::cout << "2Making a copy of " << name << " scav trap (scav copy constructor)" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "Scav trap destructor of " << name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    std::cout << "0 Entrou!!!" << std::endl;
    ClapTrap::operator=(rhs);
    std::cout << "1Creating " << name << " (scav operator=)" << std::endl;
    return *this;
}

void    ScavTrap::attack(const std::string& target) {
    ClapTrap::attack(target);
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << name << " hold the door\nhold the door\nhold door\nholdoor\nhodor\nhodor\nhodor" << std::endl;
}

