#include "Fixed.hpp"

void testComparisonOperators()
{
    Fixed a(3.1415f);
    Fixed b(2.7182f);
    Fixed c(3.1415f);

    std::cout << "Comparison Operators Test:" << std::endl;
    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << std::endl;
}

void testArithmeticOperators()
{
    Fixed a(3.1415f);
    Fixed b(2);
    Fixed c(0);

    std::cout << "Arithmetic Operators Test:" << std::endl;
    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "a * b: " << a * b << std::endl;
    std::cout << "a / b: " << a / b << std::endl;
    std::cout << "b + c: " << b + c << std::endl;
    std::cout << "b - c: " << b - c << std::endl;
    std::cout << "b * c: " << b * c << std::endl;
    try
    {
        std::cout << "b / c: " << b / c << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
}

void testIncrementDecrementOperators()
{
    Fixed a(3.1415f);
    Fixed b(2);

    std::cout << "Increment/Decrement Operators Test:" << std::endl;
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "a before pre-increment: " << a << std::endl;
    ++a;
    std::cout << "a after pre-increment: " << a << std::endl;

    std::cout << "a before post-increment: " << a << std::endl;
    a++;
    std::cout << "a after post-increment: " << a << std::endl;

    std::cout << "b before pre-decrement: " << b << std::endl;
    --b;
    std::cout << "b after pre-decrement: " << b << std::endl;

    std::cout << "b before post-decrement: " << b << std::endl;
    b--;
    std::cout << "b after post-decrement: " << b << std::endl;
    std::cout << std::endl;
}

void testMinAndMaxFunctions()
{
    Fixed a(3.1415f);
    Fixed b(2.7182f);

    std::cout << "Min and Max Functions Test:" << std::endl;
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "Minimum of a and b: " << Fixed::min(a, b) << std::endl;

    std::cout << "Maximum of a and b: " << Fixed::max(a, b) << std::endl;
    std::cout << std::endl;
}

// void testSubject()
// {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));
//     std::cout << "Subject Tests:" << std::endl;
//     std::cout << "a: " << a << " b: " << b << std::endl;
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl;
//     std::cout << std::endl;
// }

int main()
{
    // testSubject();
    testComparisonOperators();
    testArithmeticOperators();
    testIncrementDecrementOperators();
    // testMinAndMaxFunctions();

    return 0;
}
