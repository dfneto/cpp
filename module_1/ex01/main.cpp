#include "Zombie.hpp"

int main() {
    int n = 10;
    Zombie* horde = zombieHorde(n, "Paco Z");
    if (horde) {
        for (int i = 0; i < n; i++) {
            horde[i].setName("Pepe");
            horde[i].announce();
        } 
    }
    delete [] horde;
}

// As I can't do Zombie* horde = new Zombie(name)[n];
// Because C++ doesn’t allow you to pass arguments to constructors when creating an array with new[].
// To initialize each Zombie object with a specific name, you'll need to:
// Use the default constructor when allocating the array. (feito na zombieHorde)
// Set the names manually for each zombie after allocation using a setter (feito na zombieHorde)