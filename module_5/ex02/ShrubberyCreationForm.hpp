#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm&	operator=(const AForm&);

		void		execute(Bureaucrat const & executor) const = 0;

};


#endif
