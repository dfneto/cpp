#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal& ref) : type(ref.type)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "WrongAnimal Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal noises..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}