#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) {
	*this = ref;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref) {
	if (this != &ref)
		*this = ref; //TODO: acho que isso não deveria funcionar
	return (*this);
}

bool ScalarConverter::isNumber(const std::string &str) {
    bool hasDecimalPoint = false;
    size_t i = 0;
    while (i < str.length()) {
        if (std::isdigit(str[i]) || (str[i] == '.' && !hasDecimalPoint)) {
            if (str[i] == '.')
                hasDecimalPoint = true;
        }
        else  
            return false;
        i++;
    }
    return true;
}

void ScalarConverter::convert(std::string str) {

    if (isNumber(str))
        std::cout << "It's a number" << std::endl;
    else 
        std::cout << "It's NOT a number" << std::endl;

    // if (str.length() > 2 && !isNumber(str))
    // {
    //     std::cout << "Can't convert strings with length bigger than 2" << std::endl;
    //     return;
    // }

    // convert(str);

    // char cc = str[0];
    // // int i = std::atoi(str.c_str());
    // int i = static_cast<int>(cc); 
    // char c = static_cast<char>(i);
    // std::cout << "int: " << i << std::endl;
    // std::cout << "char: " << c << std::endl;
}


// str.lenght > 2 :
    // is a number? convert
    // is a string? can't convert

// converter: 
// 1
// 42
// 42.123

// char literals: ’c’, ’a’, ...
// int literals: 0, -42, 42...
// float literals: 0.0f, -4.2f, 4.2f...
// -inff, +inff, nanf
// double literals: 0.0, -4.2, 4.2...
// -inf, +inf and nan

// If a conversion to char is not displayable, prints an informative message.
