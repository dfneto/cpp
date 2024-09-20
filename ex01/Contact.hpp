#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {

    private:
        //id
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phone;
        std::string darkSecret;
    public:
        void            createContact(std::string firstName);
        std::string     getFirstName();
        void     setFirstName(std::string firstName);
        

};

#endif
