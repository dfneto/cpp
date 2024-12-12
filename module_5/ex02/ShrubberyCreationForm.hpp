#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	const std::string target;
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		void	doExecute() const;

};


#endif
