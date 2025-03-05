#include "RPN.hpp"

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation &src) {
    (void) src;
}

ReversePolishNotation&		ReversePolishNotation::operator=(const ReversePolishNotation &rhs) {
    (void) rhs;
    return *this;
}

ReversePolishNotation::ReversePolishNotation()
{
}

ReversePolishNotation::~ReversePolishNotation()
{
}

// iss >> num returns true if the number was successfully extracted.
// iss.eof() Checks if we have reached the end of the string and
// ensures that there are no extra characters after the number.
bool ReversePolishNotation::isNumber(const std::string &s) {
    std::istringstream iss(s);
    double num;
    if ((iss >> num) && (iss.eof())) {
        if (num > std::numeric_limits<double>::max()) {
            std::cerr << "Error: Number too large for double.\n";
            return false;
        }
        if (num < -std::numeric_limits<double>::max()) {
            std::cerr << "Error: Number too small for double.\n";
            return false;
        }
        return true;
    }
    return false;
}

bool ReversePolishNotation::isOperator(const std::string &s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

bool ReversePolishNotation::checkRPNInput(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return false;
    }

    int numberCount = 0;
    
    for (int i = 1; i < argc; ++i) {
        std::string token(argv[i]);

        if (isNumber(token)) {
            numberCount++;
            if (numberCount > 10) {
                std::cerr << "Error: Too many numbers (max 10 allowed)." << std::endl;
                return false;
            }
        } else if (!isOperator(token)) {
            std::cerr << "Error: Invalid token '" << token << "' detected." << std::endl;
            return false;
        }
    }

    if (numberCount == 0) {
        std::cerr << "Error: No numbers found." << std::endl;
        return false;
    }

    return true;
}
