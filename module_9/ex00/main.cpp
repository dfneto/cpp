#include "BitcoinExchange.hpp"
#include <iostream>

//I could have threated the errors as exceptions
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <filename.txt>" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    return btc.calculate(argv[1]);
}

