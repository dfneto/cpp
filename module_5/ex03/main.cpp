#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include "Intern.hpp"

int main( void ) {
    try {
        Bureaucrat bureaucrat("bureaucrat", 2);
        std::cout << bureaucrat;
        Intern intern;
        AForm *rrf;
        AForm *scf;
        AForm *ppf;
        rrf = intern.makeForm("robotomy request-----", "Pepe");
        rrf = intern.makeForm("robotomy request", "Pepe");
        scf = intern.makeForm("shrubber creation----", "Paco");
        scf = intern.makeForm("shrubbery creation", "Paco");
        ppf = intern.makeForm("presidentia pardon----", "Guido");
        ppf = intern.makeForm("presidential pardon", "Guido");
        std::cout << std::endl;
        bureaucrat.signForm(*rrf);
        bureaucrat.signForm(*scf);
        bureaucrat.signForm(*ppf);
        std::cout << std::endl;
        bureaucrat.executeForm(*scf);
        std::cout << std::endl;
        bureaucrat.executeForm(*ppf);
        std::cout << std::endl;
        bureaucrat.executeForm(*rrf);
        delete rrf;
        delete scf;
        delete ppf;
    } catch (std::exception & ex) { 
        std::cout << ex.what() << std::endl; 
    }
}
