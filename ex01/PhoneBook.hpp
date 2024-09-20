#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {

    private:
        Contact     contactList[8];
        int         indexCounter;
    public:
        PhoneBook();
        void    addContact();
        void    searchContact();
};

#endif
