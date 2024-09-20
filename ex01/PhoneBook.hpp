#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {

    private:
        Contact contactList[8];
        int     indexCounter;
        void    printContactList();
        void    printContactDetails();
        int     getSearchInput(const int n);
        bool    isNumber(const std::string& str);
        int     getSize();
    public:
        PhoneBook();
        void    addContact();
        void    searchContact();
};

#endif
