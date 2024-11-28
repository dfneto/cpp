#include "FragTrap.hpp"

// int FragTrap::baseAttack = 100;

FragTrap::FragTrap() : ClapTrap("DefatulFrag") {
    hitPoints = 999;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Frag default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Creating " << name << " frag trap (frag named constructor)" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    std::cout << "Making a copy of " << name << " frag trap (frag copy constructor)" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "frag trap destructor of " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    ClapTrap::operator=(rhs);
    std::cout << "Creating " << name << " (frag copy assignment constructor)" << std::endl;
    return *this;
}

void    FragTrap::highFivesGuys() {
    std::cout << "FragTrap high five guys!" << std::endl;
}

