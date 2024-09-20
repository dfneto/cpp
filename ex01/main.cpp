#include <iostream>
#include "PhoneBook.hpp"

int main() {

    std::string     userInput;
    PhoneBook       phoneBook;

    std::cout << "It's a phone book" << std::endl;
    std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
    std::getline(std::cin, userInput);

    while (userInput != "EXIT")
    {
        if (userInput == "ADD")
            phoneBook.addContact();
        else if (userInput == "SEARCH")
            phoneBook.searchContact();
        else {
            std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
            std::getline(std::cin, userInput);
        }
        std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, userInput);
    }
    return (0);
}
