#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) { //ampersan como parâmetro quer dizer que estou passando um objeto
    std::cout << "Copy constructor called" << std::endl;
    this->fixed = src.fixed; 
    // *this = src; Faz o mesmo que this->fixed = src.fixed só que chama também o assignment operator (operator=) em seguida
    return;
}

//Ainda que não implemente esse operator= o compilador nos fornece um por padrão 
//que faz um shallow copy, que para este caso é o suficiente
Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    //this is a pointer to the object on the left-hand side of the = operator
    //You compare this with the address of the object on the right-hand side (&other) to detect self-assignment.
    //para evitar que eu atribua a = a
    if (this != &rhs) {         //repare que estou comparando 2 ponteiros e não 2 referências 
        fixed = rhs.fixed;      //porque uma delas eh const e não posso comparar uma referência const com outr não const
    }
    return *this; // Return *this to allow chaining. Sem esse return a = b = c não é possível, porque b seria igual a c,
                  // mas não retornaria nada para atribuir a a. Agora, quando retornamos uma referência Fixed (&Fixed) e por
                  // isso fazemos um return *this, ao fazer b = c estamos atribuindo c a b e retornando b que será atribuído a a.
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
