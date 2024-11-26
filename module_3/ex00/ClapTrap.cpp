#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    this->name = "unnamed_ct";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "Creating " << name << " clap trap (default constructor)" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Creating " << name << " clap trap (named constructor)" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

//Esse construtor chama o operador= em seguida
ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "Making a copy of " << name << "clap trap (copy constructor)" << std::endl;
    *this = src; // It invokes the assignment operator!
    //Como o compilador sabe que tem que fazer uma cópia dos atributos de src para os atributos de this? Porque ele chama
    //o operator= e lá eu defino que ele deve copiar os atributos de src para this.
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    if (this != &rhs) {
        // *this = rhs; Aqui o compilador não saberia tratar isso e por isso tenho que fazer as associações abaixo
        this->name = rhs.name + "_assignmentCopy";
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
    }
    std::cout << "Creating " << name << " (copy assignment constructor)" << std::endl;
    return *this;
}

void	ClapTrap::attack(const std::string& target) {
    if (!hitPoints || !energyPoints) {
        std::cout << "ClapTrap " << name << "can't attack :/" << std::endl;
        return ;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
    if (!hitPoints) {
		std::cout << "Stop! Stop! He's Already Dead!" << std::endl;
		return;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " was hit... It loses " << amount 
            << " hit points! Now it has " << hitPoints << " hitPoints" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
    if (!energyPoints) {
        std::cout << "ClapTrap " << name << "can't be repaired :/" << std::endl;
        return ;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " fells replenished! It got " 
        << amount << " of hit points! Now it has " << hitPoints << " hitPoints" << std::endl;
}

void ClapTrap::printInfo() {
	std::cout << "Hello!\nI am " << name << "." << std::endl;
	std::cout << "My stats:\nHit points: " << hitPoints << "\nEnergy points: " << energyPoints << "\nAttack damage: " << attackDamage << std::endl;
}


