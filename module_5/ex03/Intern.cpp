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

AForm *Intern::makeForm(std::string formName, std::string target) {

    //formName -> makeShrubbery, makeRobotomy, makePardon

}
