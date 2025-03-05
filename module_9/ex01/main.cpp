#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    ReversePolishNotation rpn;
    return rpn.checkRPNInput(argc, argv);
}
