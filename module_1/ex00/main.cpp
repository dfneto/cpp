#include "Zombie.hpp"

int main() {
    Zombie z1 = Zombie("Paco");
    z1.announce();

    Zombie *z2 = newZombie("Chico");
    z2->announce();
    delete(z2);

    randomChump("Tigre");

    return (0);
}