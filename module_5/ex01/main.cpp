#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("Paco",10);
    Form form("formName", 7, 9);

    std::cout << bureaucrat;
    std::cout << form << std::endl;
    bureaucrat.signForm(form);
    std::cout << form << std::endl;

    bureaucrat.incrementGrade();

    Form form2("OtherForm", 15, 4);
    std::cout << std::endl << bureaucrat << std::endl;
    std::cout << form2 << std::endl;

    try {
        bureaucrat.signForm(form2);
    } catch (Form::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << form2 << std::endl;
	return 0;
}
