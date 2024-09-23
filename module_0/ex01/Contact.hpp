#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>      // std::setw

class Contact {

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phone;
		std::string darkSecret;
		std::string truncate(std::string const);
	public:
		Contact();
		Contact(std::string contactInfo[5]);
		void	printContact(const int i);
		void	printContactDetails(const int i);
};

#endif
