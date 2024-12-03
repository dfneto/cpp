#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string		type;

	public:
		Animal();
		Animal(const Animal &src);
		Animal(const std::string type);
		virtual ~Animal();
		
		Animal&			operator=(const Animal &rhs);

		virtual void    makeSound() const;
		std::string 	getType() const;
		void 			setType(const std::string type);
		
};
void printInfo(const std::string content);


#endif
