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

//Returns the current object (*this) by reference, meaning no 
//new object is created, and the caller operates on the same object.
//Returning a reference avoids creating a copy of the object, 
//which is more efficient. It allows chained operations like
//++x = y; // This works because `++x` returns a reference to the original `x`.
Fixed   &Fixed::operator++() {
    ++fixed;
    return *this;
}

//Returns a copy of the object and increment the current object (not the copy)
Fixed   Fixed::operator++(int) {
    //this é um ponteiro, ao fazer a deferência pegamos seu objeto
    Fixed temp(*this);  // Create a copy of the current object
    ++(*this);          // Increment the current object
    // ++(*this); eh equivalente a: ++fixed, que incrementa somente fixed
    return temp;        // Return the copy
    
}

Fixed   &Fixed::operator--() {
    --fixed;
    return *this;
}

Fixed   Fixed::operator--(int) {
    Fixed temp(fixed);
    --fixed;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { //TODO: pq não static?
    return (a < b) ? a : b;
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? const_cast<Fixed &>(a) : const_cast<Fixed &>(b); //TODO: pq esse const_cast? Qual a vantagem dessa função sobre a outra?
}

// Fixed &Fixed::min(Fixed &first, Fixed &second) { return first.getRawBits() >= second.getRawBits() ? second : first; }
// Fixed &Fixed::max(Fixed &first, Fixed &second) { return first.getRawBits() >= second.getRawBits() ? first : second; }
// const Fixed &Fixed::min(const Fixed &first, const Fixed &second) { return first.getRawBits() >= second.getRawBits() ? second : first; }
// const Fixed &Fixed::max(const Fixed &first, const Fixed &second) { return first.getRawBits() >= second.getRawBits() ? first : second; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
