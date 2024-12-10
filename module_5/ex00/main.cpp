#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bur1;
		bur1.decrementGrade();
		std::cout << bur1 << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) { //TODO: pq tem esse formato e um &e?
		// std::cerr << "TooHighException" << std::endl;
		std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		// std::cerr << "TooLowException" << std::endl;
		std::cerr << e.what() << std::endl;
	}	

	try {
		Bureaucrat bur1("Pepe", 1);
		bur1.incrementGrade();
		std::cout << bur1 << std::endl;
	} catch (std::exception &e) { 
		std::cerr << e.what() << std::endl;
	}	

	return 0;
}
