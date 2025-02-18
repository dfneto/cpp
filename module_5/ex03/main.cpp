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
        rrf = intern.makeForm("robotomy request-----", "Bender");
        rrf = intern.makeForm("robotomy request", "Eva");
        scf = intern.makeForm("shrubber creation----", "Eva");
        scf = intern.makeForm("shrubbery creation", "Bender");
        ppf = intern.makeForm("presidentia pardon----", "Nacho");
        ppf = intern.makeForm("presidential pardon", "Meri");
        std::cout << std::endl;
        bureaucrat.signForm(*rrf);
        bureaucrat.signForm(*scf);
        bureaucrat.signForm(*ppf);
        std::cout << std::endl;
        bureaucrat.executeForm(*scf);
        bureaucrat.executeForm(*ppf);
        bureaucrat.executeForm(*rrf);
        delete rrf;
        delete scf;
        delete ppf;
    } catch (std::exception & ex) { 
        std::cout << ex.what() << std::endl; 
    }
}
