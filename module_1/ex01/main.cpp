#include "Zombie.hpp"

int main() {
    int n = 10;
    Zombie* horde = zombieHorde(n, "Paco Z");
    if (horde) {
        for (int i = 0; i < n; i++) {
            horde[i].announce();
        } 
    }
    delete [] horde;
}