
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

