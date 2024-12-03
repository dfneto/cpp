#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Default Constructor" << std::endl;
}


Dog::Dog(const Dog& ref) : Animal(ref)
{
	this->brain = new Brain(*ref.brain);
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog::~Dog()
{
	delete(this->brain);
	std::cout << "Dog Destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& ref)
{
	if (this != &ref){
		this->type = ref.type;
		this->brain = new Brain(*ref.brain); //Deep copy //TODO: pq *? //TODO: testar com shallow copy
	}
	std::cout << "Dog Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Dog::makeSound() const
{
	std::cout << "Dog noises..." << std::endl;
}