
#include    <iostream>
#include    <iomanip>

int main() {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "The memory address of the string variable is " << std::setw(14) << ": " << &string << std::endl;
    std::cout << "The memory address held by stringPTR is " << std::setw(19) << ": " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is " << std::setw(19) << ": " << &stringREF << std::endl;

    std::cout << "The value of the string variable is " << std::setw(23) << ": " << string << std::endl;
    std::cout << "The value pointed to by stringPTR is " << std::setw(22) << ": " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is " << std::setw(22) << ": " << stringREF << std::endl;
}