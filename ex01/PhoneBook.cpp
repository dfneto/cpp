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

void    PhoneBook::printContactList() {
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    int i = 0;
    while (i < 2) {
        contactList[i].printContact(i);
        i++;
    }
}

//made by Lucas
bool PhoneBook::isNumber(const std::string& str) {
    int i = 0;

    if (str[i] == '-')
     i++;
    while(str[i])
    {
        if (!std::isdigit(str[i])) {
            return false;
        }
        i++;
    }
    return true;
}

//made by Lucas
int PhoneBook::getSize()
{
    if (indexCounter < 8)
        return indexCounter;
    else
        return 8;
}

//made by Lucas
int PhoneBook::getSearchInput(const int n) {
    int tmp;
    std::string input;
    
    std::cout << "Select the index of the contact that you want more information:\n>>> ";
    if (!std::getline(std::cin, input))
    {
        std::cout << "\nReturning to main...\n";
        return -1;
    }
    if (input.empty() || !isNumber(input))
    {
        std::cout << "Input is not a number!\n";
        return -1;
    }
    tmp = std::atoi(input.c_str());
    if (tmp < 0 || tmp >= n) //TODO: acho que aqui posso usar o indexCounter direto
    {
        std::cout << "Invalid index!\n";
        return -1;
    }
    return tmp;
}

void    PhoneBook::printContactDetails() {
    // std::string id;
    // std::cout << "Which contact do you want more details?" << std::endl;
    // std::getline(std::cin, id);
    // if (id < 0 || id > 8) {
    //     std::cout << "Id out of range" << std::endl;
    //     return ;
    // }
    int i = getSize();
    i = getSearchInput(i);
    if (i >= 0)
        contactList[i].printContactDetails(i);
}

void    PhoneBook::searchContact() {
    if (indexCounter == 0) {
        std::cout << "Your phonebook is empty. Nothing to see here...\n";
        return;
    }
    printContactList();
    printContactDetails();
}

