#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	name;
		const int			gradeToSign;
		const int			gradeToExecute;
		bool				isSigned;

	public:
		Form();
		Form(const Form &src);
		Form(std::string, int, int);
		~Form();
		
		Form&				operator=(const Form&);

		const std::string 	getName() const;
		int 				getGradeToSign() const;
		int 				getGradeToExecute() const;
		bool 				getIsSigned() const;

		void 				beSigned(const Bureaucrat &bur);

	
	class GradeTooHighException : public std::exception { 
			public:
				const char *what() const throw();
	};
	class GradeTooLowException : public std::exception { 
			public:
				const char *what() const throw();
	};

};
std::ostream & operator<<(std::ostream & os, const Form & form);


#endif
