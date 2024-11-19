#include "Fixed.hpp"

const int Fixed::fractionalBits = 8; //TODO: pq sem static e o lucas tem? nao basta const? pq da erro com static?

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixed = src.fixed;
    return;
}

//Ainda que não implemente esse operator= o compilador nos fornece um por padrão 
//que faz um shallow copy, que para este caso é o suficiente
Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    //this is a pointer to the object on the left-hand side of the = operator
    //You compare this with the address of the object on the right-hand side (&other) to detect self-assignment.
    if (this != &rhs) { //para evitar que eu atribua a = a
        fixed = rhs.fixed;
    }
    return *this; // Return *this to allow chaining. Sem esse return a = b = c não é possível 
    /*
    Why *this?
    1. this Is a Pointer:
        Inside a member function, this is a pointer to the current object.
        *this dereferences the pointer, yielding the object itself (by reference).
    2. Returning the Object:
        To return the current object from the assignment operator, you return *this (a reference to the current object).
        This ensures that the returned value can continue to be used in the chain.
    */
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
