#ifndef CAT_HPP
# define CAT_HPP

#include <Animal.hpp>
#include <string>
#include <iostream>

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& ref);
        ~Cat();

        Cat&	operator=(const Cat& ref);
        virtual void    makeSound() const;
    };

#endif