#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bru") , grade(150) {
    // this->name = "Bru"; -> Da erro porque name eh const
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade) {
    // *this = src; tentar com isso ao inves de por parametro e ver se atribui name
    // const_cast<std::string&>(this->_name) = other.getName();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (this->grade - 1 < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    if (this->grade + 1 > LOWEST)
        throw Bureaucrat::GradeTooLowException("Deu ruim, amigão");
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    if (this != &rhs) {
        this->grade = rhs.grade;
    }
    return *this;
}

const std::string Bureaucrat::getName() const {
    return this->name;
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
} //TODO: pq se coloco dentro do metodo da erro?

std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur) {
    os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
    return (os);
}
