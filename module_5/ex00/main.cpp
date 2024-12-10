#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bur1;
		bur1.decrementGrade();
		std::cout << bur1 << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}	

	try {
		Bureaucrat bur1;
		bur1.setName("Paula");
		Bureaucrat bur2;
		bur2 = bur1;
		std::cout << bur2.getName() << std::endl;
		bur2.incrementGrade();
		std::cout << bur2 << std::endl;
	} catch (std::exception &e) { 
		std::cerr << e.what() << std::endl;
	}	

	try {
		Bureaucrat bur2("Pepe", 1);
		bur2.incrementGrade();
		std::cout << bur2 << std::endl;
	} catch (std::exception &e) { 
		std::cerr << e.what() << std::endl;
	}	

	return 0;
}
