#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern& ref)
{
    *this=ref;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& ref)
{
    if (this != &ref)
        *this = ref;
    return (*this);
}

AForm *Intern::makeShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePardon(std::string target) {
    return new PresidentialPardonForm(target);
}

//ver modulo 1, exercicio 5 que fala de pointer member function
AForm *Intern::makeForm(std::string formName, std::string target) {

    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm*	(Intern::*functions[3])(std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePardon};
    
	for (int i = 0; i < 3; i++) {
		if (formName == forms[i])
			return (this->*functions[i])(target);
	}

    std::cout << "Error: form " << formName << " does not exist!" << std::endl;
    return NULL;
}

