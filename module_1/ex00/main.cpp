#include "Zombie.hpp"

int main() {
    Zombie z1 = Zombie("Paco");
    z1.announce();
    z1.name;

    Zombie *z2 = newZombie("Chico");
    z2->announce();
    delete(z2);

    randomChump("Tigre");

}