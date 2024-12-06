#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string		type;

	public:
		Animal();
		Animal(const Animal &src);
		Animal(const std::string type);
		virtual ~Animal();
		
		Animal&			operator=(const Animal &rhs);

		virtual void    makeSound() const = 0;
		std::string 	getType() const;
		void 			setType(const std::string type);
		
};
void printInfo(const std::string content);


#endif
