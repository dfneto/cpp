// The code demonstrates how to use pointers to member variables and member functions, as well as how to dereference them.
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <iostream> 

class Sample {
public:
    int foo;

    Sample(void) {
        foo = 0;
    };

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
    // p is a pointer to the foo member variable of the Sample class. 
    // It allows access to foo via the instance object or a pointer to instance

    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instance.*p = 21;  // Accessing 'foo' using the pointer-to-member
    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instancep->*p = 42;  // Accessing 'foo' using pointer to object and pointer-to-member
    std::cout << "Value of member foo: " << instance.foo << std::endl;

    // Assigning pointer-to-member-function 'bar'
    f = &Sample::bar;
    // f is a pointer to the bar member function of the Sample class.
    // It allows calling the bar function via the instance object or a pointer to instance.

    (instance.*f)();  // Calling the member function using pointer-to-member-function
    (instancep->*f)();  // Calling the member function using pointer to object and pointer-to-member-function

    return (0);
}

// When you write `instance.*p`, you're telling the compiler:
// - `instance`: The object of `Sample` from which we want to access the member.
// - `.*p`: The member variable (`foo` in this case) that is pointed to by `p`.
// Similarly, when you use `instancep->*p`, you're dereferencing the pointer `instancep` to get the object and then accessing the member `foo` via the pointer `p`.