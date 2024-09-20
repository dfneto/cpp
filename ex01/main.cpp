#include <iostream>
// #include "PhoneBook.hpp"

int main() {

    std::string     userInput;
    // PhoneBook       phoneBook;

    std::cout << "It's a phone book" << std::endl;
    std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
    std::getline(std::cin, userInput);

    while (userInput != "EXIT")
    {
        if (userInput == "ADD") {
            std::cout << "Weeeeeeeee" << std::endl;
            //ADD
            //Contact contact;
            //criar um contato passando os valores do input: contact.create
            //phoneBook.add(contact)
        }
        else {
            std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
            std::getline(std::cin, userInput);
        }
        std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, userInput);
    }
    return (0);
}
