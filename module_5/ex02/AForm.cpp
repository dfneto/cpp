#include "AForm.hpp"

AForm::AForm() : 
    name("Empty AForm"), gradeToSign(0), 
    gradeToExecute(0), isSigned(false) {}

AForm::AForm(const AForm &src) : 
    name(src.name), gradeToSign(src.gradeToSign), 
    gradeToExecute(src.gradeToExecute), isSigned(src.isSigned) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
    name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute),
    isSigned(false) {
    if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
        throw AForm::GradeTooHighException();
    if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs) {
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

const std::string AForm::getName() const {
    return this->name;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("AForm Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("AForm Grade too low");
}

void    AForm::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;

}

//Nao poderia usar this->name porque operator nao faz parte da classe 
//e por isso nao tem this. Entao tenho que usar os getters da mesma AForma
//que faco quando preciso de name fora da classe.
std::ostream & operator<<(std::ostream & os, const AForm & AForm) {
    std::string status;
	if (AForm.getIsSigned())
		status = "Ready to Go";
	else
		status = "Pending signature";
    os << ">>AForm: " << AForm.getName() << "\n>>Signed: " << status <<
	"\n>>Sign Grade: " << AForm.getGradeToSign() << "\n>>Execution Grade: " << AForm.getGradeToExecute();
    return (os);
}
