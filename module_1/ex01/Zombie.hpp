#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    std::string name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void setName(std::string name);
        void announce();
};

//non-member functions (outside of the class):
Zombie* zombieHorde(int n, std::string name);

#endif

//As I can't do Zombie* horte = new Zombie(name)[n];
//C++ doesn’t allow you to pass arguments to constructors when creating an array with new[].
// To initialize each Zombie object with a specific name, you'll need to:
// Use the default constructor when allocating the array.
// Set the names manually for each zombie after allocation using a setter