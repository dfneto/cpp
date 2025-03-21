#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) {
	*this = ref;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref) {
	if (this != &ref)
		*this = ref; //This is calling the same operator= function you are currently implementing -> infinite recursion
	return (*this);
}

void ScalarConverter::convertSingleChar(char cc) {
    int int_value = static_cast<int>(cc);
    char c = static_cast<char>(int_value);
    float f = static_cast<float>(int_value);
    double d = static_cast<double>(int_value);
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << int_value << std::endl;
    // Ensure .0 for float and double
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

int ScalarConverter::handleSpecialCases(const std::string str) {
    if (str == "-inff" || str == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return 1;
    }
    if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return 1;
    }
    if (str == "nanf" || str == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return 1;
    }
    return 0;
}

void ScalarConverter::convert(std::string str) {
    if (str.length() == 1 && !std::isdigit(str[0])) {
        convertSingleChar(str[0]);
        return ;
    }
    if (handleSpecialCases(str))
        return ;
    convertString(str);
    return;
}

int ScalarConverter::isInteger(std::string str) {
    size_t i = 0;

    // Allow a leading '+' or '-'
    if (str[i] == '+' || str[i] == '-') {
        if (str.length() == 1)  // A single '+' or '-' is not an integer
            return 0;
        i++;
    }

    // Check if the rest of the string consists only of digits
    for (; i < str.length(); i++) {
        if (!std::isdigit(str[i]))  // If any character is not a digit, return false
            return 0;
    }

    return 1;  // The string is a valid integer
}

int ScalarConverter::isFloatOrDouble(std::string str) {
    size_t i = 0;
    int hasDecimal = 0;
    int hasDigit = 0;  
    int hasF = 0;

    if (str[i] == '+' || str[i] == '-') {
        if (str.length() == 1)
            return 0;
        i++;
    }

    for (; i < str.length(); i++) {
        if (std::isdigit(str[i])) {
            hasDigit = 1;  
        } else if (str[i] == '.') {
            if (hasDecimal)
                return 0;
            hasDecimal = 1;
        } else if (str[i] == 'f' || str[i] == 'F') {
            if (i != str.length() - 1 || hasF)
                return 0;
            hasF = 1;
        } else {
            return 0;
        }
    }

    // ✅ Ensure at least one digit exists, avoiding cases like "." or ".f"
    return hasDigit && (hasDecimal || hasF);
}

//O caso de int e float são muito parecidos
//intPattern matches: 123, -123, 0. Don't: 123.45, abc, ""
//floatPattern matches: 123.45, -123.45, .45, 123.0f, -0.01f. Don't: 123, abc, 1.23.45, f
void ScalarConverter::convertString(const std::string &str) {
    if (isInteger(str)) {
        try {
            long int_value = std::strtol(str.c_str(), NULL, 10); // Convert string to long
            if (int_value > INT_MAX || int_value < INT_MIN) {
                throw std::out_of_range("Integer out of range");
            }
            int i = static_cast<int>(int_value);
            char c = static_cast<char>(i);
            float f = static_cast<float>(i);
            double d = static_cast<double>(i);

            std::cout << "char: ";
            if (i >= 32 && i <= 126)
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "Non-displayable" << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        } catch (...) {
            std::cerr << "Error: Integer out of range" << std::endl;
        }
        return;
    }

    // Check if the input is a float or double
    if (isFloatOrDouble(str)) {
        try {
            double d = std::strtod(str.c_str(), NULL); // Convert string to double
            float f = static_cast<float>(d);
            int i = static_cast<int>(d);
            char c = static_cast<char>(i);

            std::cout << "char: ";
            if (i >= 32 && i <= 126)
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "Non-displayable" << std::endl;

            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        } catch (...) {
            std::cerr << "Error: Invalid floating-point conversion" << std::endl;
        }
        return;
    }

    // If no valid case matches, print an error
    std::cerr << "Error: Invalid input" << std::endl;
}

// converter: 
// -inff, +inff, nanf
// -inf, +inf and nan
// 42.123
// 42.2f
// 1
// 42
// -1
// a [ok]
// ab -> nop [ok]
// 1a -> nop [ok]
// Max int [ok]
// Min int [ok]

// char literals: ’c’, ’a’, ...
// int literals: 0, -42, 42...
// float literals: 0.0f, -4.2f, 4.2f...
// double literals: 0.0, -4.2, 4.2...
