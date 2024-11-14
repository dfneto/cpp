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