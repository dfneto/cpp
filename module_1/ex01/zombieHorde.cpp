#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
    if (n <= 0) return NULL;

    // Allocate an array of n Zombies using the default constructor
    Zombie* horde = new Zombie[n];
    for (int i = 0; i < n; i++) {
        horde[i].setName(name);
    }
    return horde;
}
// In C++, arrays are laid out sequentially in memory (each Zombie object is placed next to 
// the previous one in memory), so when you allocate an array of objects using new Zombie[n],
// the pointer to the array (in this case, horde) points to the first element of the array. Using 
// this pointer you can access other elements in the array by indexing or pointer arithmetic.