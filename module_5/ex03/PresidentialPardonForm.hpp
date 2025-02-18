#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	const std::string target;
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		void	doExecute() const;

};


#endif
