
#include "Contact.hpp"

void    Contact::createContact(std::string firstName) {
    this->firstName = firstName;
}

std::string    Contact::getFirstName() {
    return this->firstName;
}

void     Contact::setFirstName(std::string firstName) {
    this->firstName = firstName;
}
