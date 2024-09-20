#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->indexCounter = 0;
}

void    PhoneBook::addContact() {
    // forma mais estilo OO
    // std::getline(std::cin, firstName);
    // Contact contact;
    // contact.setFirstName(firstName);
    // contactList[indexCounter % 2] = contact;
    int         i = 0;
    std::string contactInfo[5];

    std::cout << "Insert a new contact. Fill the following fields: \n\
    1. First name \n\
    2. Last name \n\
    3. Nickname \n\
    4. Phone number \n\
    5. Dark secret (uhhh o:)" << std::endl;
    
    while (i < 5)
    {
        std::cout << "Insert item " << i + 1 << ": ";
        std::getline(std::cin, contactInfo[i]);
        if (!contactInfo[i].empty())
            i++;
        else
            std::cout << "Field cannot be empty... Try again!\n";   
    }
    Contact contact(contactInfo);
    contactList[indexCounter % 2] = contact;
    indexCounter++;
}

void    PhoneBook::searchContact() {
    if (indexCounter == 0) {
        std::cout << "Your phonebook is empty. Nothing to see here...\n";
        return;
    }
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    int i = 0;
    while (i < 2) {
        contactList[i].printContact(i);
        i++;
    }
}

