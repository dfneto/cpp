#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bru") , grade(150) {
    // this->name = "Bru"; -> Da erro porque name eh const
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade) {
    // Como name eh const eu nao posso fazer this->name = src.name.
    // Entao devo setar name como member initializer list ou:
    // const_cast<std::string&>(this->name) = src.name;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    if (grade > LOWEST)
        throw Bureaucrat::GradeTooLowException("Deu ruim, amigão");
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    if (this != &rhs) {
        const_cast<std::string&>(this->name) = rhs.name;
        this->grade = rhs.grade;
    }
    return *this;
}

const std::string Bureaucrat::getName() const {
    return this->name;
}

void    Bureaucrat::setName(std::string newName) {
    const_cast<std::string&>(this->name) = newName;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void    Bureaucrat::incrementGrade() {
    if (this->grade - 1 < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void    Bureaucrat::decrementGrade() {
    if (this->grade + 1 > LOWEST)
        throw Bureaucrat::GradeTooLowException("Deu ruim, amigão");
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string msg) : std::out_of_range(msg + ". Grade too low") {
// Se coloco dentro do metodo da erro, pois:
// In a derived class, the base class must be fully 
// constructed before any code in the body of the derived 
// class constructor executes. For this reason you need
// to use the member initializer list to explicitly invoke
// the base class constructor.
}



std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur) {
    os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
    return (os);
}
