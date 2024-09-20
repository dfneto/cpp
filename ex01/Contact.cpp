
#include "Contact.hpp"

Contact::Contact() {
    //Constructor necessary to declare an array of Contacts in PhoneBook
}

Contact::Contact(std::string contactInfo[5]) {
    firstName = contactInfo[0];
    lastName = contactInfo[1];
    nickName = contactInfo[2];
    phone = contactInfo[3];
    darkSecret = contactInfo[4];
}

void    Contact::createContact(std::string firstName) {
    this->firstName = firstName;
}

std::string    Contact::getFirstName() {
    return this->firstName;
}

void     Contact::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

std::string Contact::truncate(std::string const string) {
    if (string.length() > 10)
        return string.substr(0, 9) + ".";
    else
        return string;
}

void    Contact::printContact(const int i) {
    if (firstName.empty())
        return ;
    std::cout << "|" << std::setw(10) << std::right << i;
    std::cout << "|" << std::setw(10) << std::right << truncate(firstName);
    std::cout << "|" << std::setw(10) << std::right << truncate(lastName);
    std::cout << "|" << std::setw(10) << std::right << truncate(nickName) << "|";
    std::cout << std::endl;
}

