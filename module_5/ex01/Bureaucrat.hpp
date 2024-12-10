#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define HIGHEST	1
#define LOWEST	150

class Form; //to avoid circular dependencies and unnecessary inclusions

class Bureaucrat {
	protected:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(std::string, int);
		~Bureaucrat();
		
		Bureaucrat&			operator=(const Bureaucrat &rhs);

		const std::string 	getName() const;
		int		 			getGrade() const;
		void				setName(std::string);
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form &form);

		class GradeTooHighException : public std::exception { 
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::out_of_range { //out_of_range is a subclass of std::exception
			public:
				GradeTooLowException(std::string msg);
		};
		
};
std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur);


#endif
