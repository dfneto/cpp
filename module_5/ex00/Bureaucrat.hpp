#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define HIGHEST	1
#define LOWEST	150

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
		int		 	getGrade() const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		class GradeTooHighException : public std::exception { 
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::out_of_range { //TODO: pq funciona com out_of_range? Sera pq vem do std::exception?
			public:
				GradeTooLowException(std::string msg);
		};
		
};
std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur);


#endif
