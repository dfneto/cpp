#include "Base.hpp"

Base::~Base() {}

Base    *generate(void) {
    std::srand(std::time(NULL));
    std::cout << "Generating: ";
    switch (std::rand() % 3) {
        case 0:
            std::cout << "A class" << std::endl;
            return (new A());
        case 1:
            std::cout << "B class" << std::endl;
            return (new B());
        case 2:
            std::cout << "C class" << std::endl;
            return (new C());
        default:
            return NULL;    
    }
}

void    identify(Base *ptr) {
    if (dynamic_cast<A*>(ptr)) {
        std::cout << "Pointer is of type A*" << std::endl;
    } else if (dynamic_cast<B*>(ptr)) {
        std::cout << "Pointer is of type B*" << std::endl;
    } else if (dynamic_cast<C*>(ptr)) {
        std::cout << "Pointer is of type C*" << std::endl;
    } else {
        std::cout << "Pointer is of unknown type" << std::endl;
    }
}

void    identify(Base &ref) {
     try {
        A& a = dynamic_cast<A&>(ref);
        (void)a;
        std::cout << "Reference is of type A&" << std::endl;
    } catch (std::bad_cast&) {
        try {
            B& b = dynamic_cast<B&>(ref);
            (void)b;
            std::cout << "Reference is of type B&" << std::endl;
        } catch (std::bad_cast&) {
            try {
                C& c = dynamic_cast<C&>(ref);
                (void)c;
                std::cout << "Reference is of type C&" << std::endl;
            } catch (std::bad_cast&) {
                std::cout << "Reference is of unknown type" << std::endl;
            }
        }
    }
}
