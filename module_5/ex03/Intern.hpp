#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	AForm *makeShrubbery(std::string target);
	AForm *makeRobotomy(std::string target);
	AForm *makePardon(std::string target);
public:
	Intern();
	Intern(const Intern& ref);
	~Intern();

	Intern&	operator=(const Intern& ref);

	AForm *makeForm(std::string formName, std::string target);
};

#endif
