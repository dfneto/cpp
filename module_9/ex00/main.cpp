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

//fazer o check de erros
//ler o csv e colocar num dicionario
//ler o input e para cada linha:
    //calcular o resultado
    //imprimir 2011-01-03 => 3 = 0.9




// ##input
// *data --------------------------------> pegar nesta data o exchange rate e multiplicar pela qtd de btc
// *qtd de btcs