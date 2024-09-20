#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>      // std::setw

class Contact {

    private:
        //id
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phone;
        std::string darkSecret;
        std::string truncate(std::string const);
    public:
        Contact();
        Contact(std::string contactInfo[5]);
        void            createContact(std::string firstName);
        std::string     getFirstName();
        void     setFirstName(std::string firstName);
        void            printContact(const int i);
        

};

#endif
