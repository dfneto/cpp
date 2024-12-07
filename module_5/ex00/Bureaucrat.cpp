#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bru") , grade(150) {
    // this->name = "Bru"; -> Da erro porque name eh const
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    *this = src;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat of type " << this->type << " destroyed!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    if (this != &rhs) {
        this->grade = rhs.grade;
    }
    std::cout << "Operator= of type " << type << ". Bureaucrat operator= called" << std::endl;
    return *this;
}


std::string Bureaucrat::getType() const {
    return this->type;
}

