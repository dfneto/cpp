#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

//TODO: goal: ver os leaks de brain dos animais se nao deleto e ver a deep copy vs shallow copy

void subjectTest(void)
{
	std::cout << "Subject tests:" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl << std::endl;
}

// int main()
// {
// 	Animal animal[100];
// 	for (int i=0; i < 50; i++)
// 		animal[i] = * new Dog();
// 	return 0;
// }

void arrayTest(void)
{
	std::cout << "Array tests:" << std::endl;
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
	std::cout << "Copy tests:" << std::endl;
	Cat cat;
	Cat copy = cat;

	std::cout << "Cat brain: ";
	cat.printBrain();
	std::cout << "Copy brain: ";
	copy.printBrain();
}

int main() {
	subjectTest();
	// arrayTest();
	// copyTest();
	return 0;
}