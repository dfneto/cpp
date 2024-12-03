#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor" << std::endl;
}


Dog::Dog(const Dog& ref) : Animal(ref)
{
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "Dog Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Dog::makeSound() const
{
	std::cout << "Dog noises..." << std::endl;
}