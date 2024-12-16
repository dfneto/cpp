#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <regex>


# define E "\033[m"                 //end
# define R "\033[1m\033[1;31m"      //red
# define G "\033[1m\033[1;32m"      //green
# define Y "\033[1m\033[1;33m"      //yellow
# define B "\033[1;34m"             //blue
# define T "\033[1m\033[1;35m"      //Turquesa
# define C "\033[1;36m"             //Cyan
# define O "\033[1m\033[38;5;208m"  //orange
# define F "\033[1m\033[38;5;128m"  //purple

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &ref);
    ~ScalarConverter();

    ScalarConverter &operator=(const ScalarConverter &ref);
    static void convertSingleChar(char);
    static void convertString(const std::string &);
    static int handleSpecialCases(const std::string);

public:
    static void convert(std::string);

};

#endif
