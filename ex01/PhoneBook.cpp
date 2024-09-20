#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->indexCounter = 0;
}

void    PhoneBook::addContact(){
    std::cout << "Write the first name" << std::endl;
    std::getline(std::cin, firstName);
    // contacts[0].firstName = userInput;
    // contacts[0].createContact(firstName);
    Contact contact;
    contact.setFirstName(firstName);
    contactList[indexCounter % 2] = contact;
    indexCounter++;
}

void    PhoneBook::searchContact(){
    int i = 0;
    while (i < 2){
        std::cout << contactList[i % 2].getFirstName() << std::endl;
        i++;
    }
}

