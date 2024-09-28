#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <iostream> 

class Sample {
public:
    int foo;  // Public integer member

    // Constructor
    Sample(void) {
        foo = 0;
    };

    // Destructor
    ~Sample(void) {}

    // Const member function
    void bar(void) const {
        std::cout << "pepo waka waka" << std::endl;
    }
};

#endif

int main() {
    Sample instance;
    Sample* instancep = &instance;

    int Sample::*p = NULL;
    void (Sample::*f)(void) const;

    // Assigning pointer-to-member-variable 'foo'
    p = &Sample::foo;

    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instance.*p = 21;  // Accessing 'foo' using the pointer-to-member
    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instancep->*p = 42;  // Accessing 'foo' using pointer to object and pointer-to-member
    std::cout << "Value of member foo: " << instance.foo << std::endl;

    // Assigning pointer-to-member-function 'bar'
    f = &Sample::bar;

    (instance.*f)();  // Calling the member function using pointer-to-member-function
    (instancep->*f)();  // Calling the member function using pointer to object and pointer-to-member-function

    return (0);
}

