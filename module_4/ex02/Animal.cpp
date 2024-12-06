#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
    this->type = "Generic animal";
}

Animal::Animal(const std::string type) : type(type) {
    std::cout << "Animal named constructor called - type: " << type << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "Making a copy of animal type " << src.type << ". Animal copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal() {
    std::cout << "Animal of type " << this->type << " destroyed!" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
    if (this != &rhs) {
        this->type = rhs.type; //sem essa linha o compilador nao sabe o que copiar
    }
    std::cout << "Operator= of type " << type << ". Animal operator= called" << std::endl;
    return *this;
}

void Animal::setType(const std::string type) {
    this->type = type;
}

std::string Animal::getType() const {
    return this->type;
}

void printInfo(const std::string content) {
    std::cout << "printer>>"<< content << std::endl;
}
