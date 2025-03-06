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

double ReversePolishNotation::applyOperator(double left, double right, char op)
{
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': 
            if (right == 0) 
                throw std::runtime_error("Error: Division by zero!"); 
            return left / right;
        default:
            throw std::runtime_error("Error: Invalid operator!");
    }
}

double ReversePolishNotation::calculateRPN(char *argv) {
    if (!checkRPNInput(argv))
        return 1;
    return makeTheMath(argv);
}

bool ReversePolishNotation::checkRPNInput(char *argv)
{
    int numberCount = 0;
    std::istringstream iss(argv);  // Convert CLI input to istringstream
    std::string token;

    while (iss >> token) {
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

double ReversePolishNotation::makeTheMath(char *argv) {
    std::istringstream iss(argv);  // Convert CLI input to istringstream
    std::string token;

    while (iss >> token) {
        if (isOperator(token)) {

            if (this->stack.size() < 2)
                throw std::runtime_error("some problem in the sequence of number \
                and operators! You should garantee that before an operator \
                you have at least two numbers."); 
            char op = token[0];
            double left, right;
            right = this->stack.top();
            stack.pop(); 
            left = this->stack.top();
            stack.pop(); 

            this->stack.push(applyOperator(left, right, op));
        } else {
            this->stack.push(std::atof(token.c_str()));
        }
    }
    return this->stack.top();
}
