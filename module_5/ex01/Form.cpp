#include "Form.hpp"

Form::Form() : 
    name("Empty form"), gradeToSign(0), 
    gradeToExecute(0), isSigned(false) {}

Form::Form(const Form &src) : 
    name(src.name), gradeToSign(src.gradeToSign), 
    gradeToExecute(src.gradeToExecute), isSigned(src.isSigned) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
    name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute),
    isSigned(false) {
    if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
        throw Form::GradeTooHighException();
    if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs) {
        //you can use const_cast to cast away the const qualifier 
        //of a const int and attempt to change its value, but doing 
        //so results in undefined behavior if the const int was 
        //originally declared as const
        const_cast<std::string&>(this->name) = rhs.name;
        const_cast<int&>(this->gradeToSign) = rhs.gradeToSign;
        const_cast<int&>(this->gradeToExecute) = rhs.gradeToSign;
        this->isSigned = rhs.isSigned;
    }
    return *this;
}

const std::string Form::getName() const {
    return this->name;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Form Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Form Grade too low");
}

void    Form::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
}

//Nao poderia usar this->name porque operator nao faz parte da classe 
//e por isso nao tem this. Entao tenho que usar os getters da mesma forma
//que faco quando preciso de name fora da classe.
std::ostream & operator<<(std::ostream & os, const Form & form) {
    std::string status;
	if (form.getIsSigned())
		status = "Ready to Go";
	else
		status = "Pending signature";
    os << ">>Form: " << form.getName() << "\n>>Signed: " << status <<
	"\n>>Sign Grade: " << form.getGradeToSign() << "\n>>Execution Grade: " << form.getGradeToExecute();
    return (os);
}
