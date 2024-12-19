#include "Iter.hpp"
#include <iostream>

template <typename T> void printElement(T &e) {
    std::cout << e << " ";
}

template <typename T> void doubleElement(T &e) {
    e *= 2;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"Pepe", "Paco", "Jaume", "Pepo", "Juan"};

    std::cout << "# Printing intArray:" << std::endl;
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "# Printing doubleArray:" << std::endl;
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    std::cout << "# Printing stringArray:" << std::endl;
    iter(stringArray, 5, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "# Double intArray:" << std::endl;
    iter(intArray, 5, doubleElement<int>);
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "# Double doubleArray:" << std::endl;
    iter(doubleArray, 5, doubleElement<double>);
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;
	return (0);
}
