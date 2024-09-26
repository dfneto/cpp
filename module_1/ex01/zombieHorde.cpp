#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
    if (n <= 0) return nullptr;

    // Allocate an array of n Zombies using the default constructor
    Zombie* horde = new Zombie[n];
    for (int i = 0; i < n; i++) {
        horde[i].setName(name);
    }
    return horde;
}
// In C++, arrays are laid out sequentially in memory, so when you allocate an array of objects, the pointer to the array (in this case, horde) points to the first element of the array. Using this pointer, you can access other elements in the array by indexing or pointer arithmetic.
// When you create an array of n Zombie objects using new Zombie[n], the memory layout is such that each Zombie object is placed next to the previous one in memory.
// By returning the pointer to the first element of the array, you can use pointer arithmetic or array indexing to access the other elements.