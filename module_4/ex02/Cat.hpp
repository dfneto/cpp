#ifndef CAT_HPP
# define CAT_HPP

#include <Animal.hpp>
#include <Brain.hpp>
#include <iostream>

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& ref);
        ~Cat();

        Cat&	operator=(const Cat& ref);
        virtual void    makeSound() const; //Sem o virtual da igual
    };

#endif