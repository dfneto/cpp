#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

//TODO: ver a deep copy vs shallow copy

void subjectTest(void)
{
	std::cout << ">> Subject tests:" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << ">> Destruction ..." << std::endl;
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl << std::endl;
}

void arrayTest(void)
{
	std::cout << ">>Array tests:" << std::endl;
	int numAnimals = 2;
	Animal *animalArray[2];

	for (int i = 0; i < numAnimals; i++)
	{ 
		if (i < numAnimals / 2)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
	}
	for (int i = 0; i < numAnimals; i++)
		delete animalArray[i];
	std::cout << std::endl << std::endl;
}

void copyTest(void)
{
	std::cout << ">> Copy tests:" << std::endl;
	Dog dog;
	Dog copy = dog;

	std::cout << "Dog brain: ";
	dog.printBrain();
	std::cout << "Copy brain: ";
	copy.printBrain();
}

//AQUI: TODO: quero chamar o construtor com parametro de dog e o de brain que faca a copia de ideas e entender pq 
//Dog brain: Type: Dog. Brain: 0x55965d3dc2c0. Ideas: 0x55965d3dc2c0 eh o mesmo ponteiro
void objectConstructorTest() {
	std::cout << ">> Object Constructor tests:" << std::endl;
	Dog dog;
	Dog newDopy(dog);

	std::cout << "Dog brain: ";
	dog.printBrain();
	std::cout << "Copy brain: ";
	newDopy.printBrain();
}

int main() {
	// subjectTest();
	// arrayTest();
	// copyTest();
	objectConstructorTest();
	return 0;
}