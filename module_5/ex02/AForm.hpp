#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string	name;
		const int			gradeToSign;
		const int			gradeToExecute;
		bool				isSigned;

	public:
		AForm();
		AForm(const AForm &src);
		AForm(std::string, int, int);
		virtual ~AForm();
		
		AForm&				operator=(const AForm&);

		const std::string 	getName() const;
		int 				getGradeToSign() const;
		int 				getGradeToExecute() const;
		bool 				getIsSigned() const;

		void 				beSigned(const Bureaucrat &bur);
		void				execute(Bureaucrat const & executor) const;
		virtual  void		doExecute() = 0;

	
	class GradeTooHighException : public std::exception { 
			public:
				const char *what() const throw();
	};
	class GradeTooLowException : public std::exception { 
			public:
				const char *what() const throw();
	};

};
std::ostream & operator<<(std::ostream & os, const AForm & AForm);


#endif
