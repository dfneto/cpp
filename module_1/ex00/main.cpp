#include "Zombie.hpp"

int main() {
    //Aloco na stack e por isso nao posso deletar z1
    Zombie z1 = Zombie("Paco");
    z1.announce();
    z1.setName("Robson");
    //delete(z1) -> erro porque z1 eh gerenciado pela stack

    //Aloco na heap
    Zombie *z2 = newZombie("Chico");
    z2->announce();
    delete(z2);

    randomChump("Tigre");

    return (0);
}