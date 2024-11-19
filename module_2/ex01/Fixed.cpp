#include "Fixed.hpp"

//For a fixed-point number, the integer part and fractional part are stored in a single integer 
//The number 3.75 is stored as 3.75 * (2^fractionalBits), where fractionalBits is 8. 
//This means 3.75 is stored as 960 (in raw integer form). When calling toFloat(), 
//it converts 960 back to 3.75 by dividing by (2^8).

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->fixed = value * (1 << fractionalBits);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->fixed = roundf(value * (1 << fractionalBits));
    // std::cout << "Armazenando fixed=" << this->fixed << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixed = src.fixed;
    return;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        fixed = rhs.fixed;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed;
}

void Fixed::setRawBits(int const raw) {
    this->fixed = raw;
}

int Fixed::toInt() const {
    return this->fixed / (1 << fractionalBits);
}

float Fixed::toFloat() const {
    return static_cast<float>(this->fixed) / (1 << fractionalBits); //TODO:EXPERIMENTAR SEM O CAST
}

//An overload of the insertion (<<) operator allows you to define how your custom class 
//objects are displayed when used with an output stream, such as std::cout. Specifically, 
//in your case, the operator will output a floating-point representation of the fixed-point number.
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
