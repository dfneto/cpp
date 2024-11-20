#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixed(0) {
}

Fixed::Fixed(const int value) {
    this->fixed = value * (1 << fractionalBits);
}

Fixed::Fixed(const float value) {
    this->fixed = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
    this->fixed = src.fixed;
    return;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    if (this != &rhs) {
        fixed = rhs.fixed;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    return this->fixed;
}

void Fixed::setRawBits(int const raw) {
    this->fixed = raw;
}

int Fixed::toInt() const {
    return this->fixed / (1 << fractionalBits);
}

float Fixed::toFloat() const {
    return static_cast<float>(this->fixed) / (1 << fractionalBits);
}

Fixed Fixed::operator+(const Fixed &rhs) const {
    //estou criando uma nova instância que apesar de gastar um pouco de memória
    //me permite fazer chaining, coisa que não poderia se retornasse um ponteiro
    //para stack
    return Fixed(this->toFloat() + rhs.toFloat()); 
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs.toFloat() == 0.0)
        throw std::invalid_argument("Can not divide by zero!");
    return Fixed(this->toFloat() / rhs.toFloat());
}

bool Fixed::operator>(const Fixed &rhs) const {
    return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<(const Fixed &rhs) const {
	return toFloat() < rhs.toFloat();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return toFloat() <= rhs.toFloat();
}

bool Fixed::operator==(const Fixed &rhs) const {
	return toFloat() == rhs.toFloat();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return toFloat() != rhs.toFloat();
}

Fixed   &Fixed::operator++() {
    fixed++;
    return *this;
}

Fixed   &Fixed::operator++(int) {
    this->fixed
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
