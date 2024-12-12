#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	const std::string target;
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm&);

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		void	doExecute() const;

};


#endif
