#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie() {
    std::cout << name << " died ..." << std::endl;
}
void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}