#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    std::cout << a.getRawBits() << std::endl;
	a.setRawBits(42);
    Fixed b(a);
    Fixed c;
    c = b;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return (0);
}
