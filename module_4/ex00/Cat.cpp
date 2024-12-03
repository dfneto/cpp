#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "Cat Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Cat::makeSound() const
{
	std::cout << "Cat noises..." << std::endl;
}
