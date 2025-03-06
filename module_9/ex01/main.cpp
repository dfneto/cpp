#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    ReversePolishNotation rpn;
    try {
        std::cout << "RPN is: " << rpn.calculateRPN(argv[1]) << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
