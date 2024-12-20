#include "Array.hpp"
#include <iostream>

int main() {
    Array<int> empty;
    std::cout << "Array size: " << empty.getSize() << std::endl;

    Array<double> doubleArray(5);
    std::cout << "Array size: " << doubleArray.getSize() << std::endl;

    std::cout << "double array: ";
    doubleArray[0] = 42;
    for (unsigned int i = 0; i < doubleArray.getSize(); ++i) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    const Array<int> constArray (5);
    std::cout << "const array: ";
    for (unsigned int i = 0; i < constArray.getSize(); ++i) {
        std::cout << constArray[i] << " ";
    }
    std::cout << std::endl;
    //constArray[0] = 1; //compilation error, trying to modify const array

    Array<char> charArray(3);
    charArray[0] = 'O';
    charArray[1] = 'A';
    charArray[2] = '2';

    Array<char> copiedArray = charArray;
    copiedArray[0] = 'D';

    std::cout << "char array: ";
    for (unsigned int i = 0; i < charArray.getSize(); ++i) {
        std::cout << charArray[i]; //0 A 2
    }
    std::cout << std::endl;
    std::cout << "copied array: " << copiedArray[0] << copiedArray[1] << copiedArray[2] << std::endl;

    try {
        std::cout << charArray[0] << std::endl;
        std::cout << charArray[3] << std::endl;
    } catch (std::exception& e) { 
        //By catching the exception by reference (std::exception& e), 
        //you ensure that the specific exception type and its associated 
        //message are preserved and not sliced.
        std::cerr << "Exceção lançada: " << e.what() << std::endl;
    }

	return (0);
}
