#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <filename.txt>" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc;
        return btc.calculate(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
}
