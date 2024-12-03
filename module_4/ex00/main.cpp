#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// std::cout << ">> Let's start ..." << std::endl << std::endl;
	// Animal animal;
	// printInfo(animal.getType());
	
	// std::cout << "2----------------------------" << std::endl;
	// Animal ani2("zat");
	// printInfo(ani2.getType());

	// std::cout << "3----------------------------" << std::endl;
	// Animal ani3(ani2);
	// printInfo(ani3.getType());

	// std::cout << "4(cat)-----------------------" << std::endl;
	// Cat cat;
	// printInfo(cat.getType());

	std::cout << "----------------------------" << std::endl;
	std::cout << "Subject tests" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "type: " << meta->getType() << " " << std::endl;
	std::cout << "type: " << j->getType() << " " << std::endl;
	std::cout << "type: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound(); //won't output nothing because it has no implementation
	//As these are pointers we have to free than explicitly
	delete meta;
	delete i;
	delete j;

	std::cout << "\nCreating WrongAnimals... why? Don't know..." << std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongi = new WrongCat();
	std::cout << wrongmeta->getType() << " " << std::endl;
	std::cout << wrongi->getType() << " " << std::endl;
	wrongi->makeSound(); //will output the wronganimal sound!
	wrongmeta->makeSound();

	delete wrongmeta;
	delete wrongi;
	return 0;
}
