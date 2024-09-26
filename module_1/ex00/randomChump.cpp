#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie z1 = Zombie(name);
    z1.announce();
}