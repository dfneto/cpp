#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Default Constructor" << std::endl;
}

//Por que *ref.brain? 
//para ponteiro usamos ->
//para referencia usamos .
//ref.brain eh um ponteiro e o que queremos eh acessar o objeto (por isso usamos * em ref.brain)
//pq eh o que pede o construtor de Brain [Brain(const Brain& ref)], o qual vai me devolver
//um ponteiro
Dog::Dog(const Dog& ref) : Animal(ref) {
	this->brain = new Brain(*ref.brain); // ref.brain; //shallow copy
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
		this->brain = new Brain(*ref.brain);
	}
	std::cout << "----------------Dog Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Dog::makeSound() const
{
	std::cout << "Dog noises..." << std::endl;
}

void	Dog::printBrain() const {
	//The Brain object itself and its ideas array share the same starting 
	//address because ideas is the first member of the Brain class. There
	//is no offset or padding before ideas.
	std::cout << "Type: " << this->type << ". Brain: " << this->brain << ". Ideas: " << this->brain->ideas << std::endl;
}