#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor" << std::endl;
}


WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "WrongCat Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    WrongCat::makeSound() const
{
	std::cout << "WrongCat noises..." << std::endl;
}