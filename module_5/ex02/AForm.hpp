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
		virtual  void		doExecute() const = 0; 
		//Tem que ser const porque o método execute que chama doExecute eh const
		//Deixei privado para não ser acessível em Bureacrat e saltar as checagens que 
		//geram exceções de execute. Ou seja, doExecute sendo privado obriga a bureucrat
		//chamar execute, onde são feito checagens e que chama doExecute. Se doExecute
		//fosse público poderia ser chamado direto da classe bureaucrat e evitar checagens
		
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
		void				execute(const Bureaucrat &executor) const;

	
	class GradeTooHighException : public std::exception { 
			public:
				const char *what() const throw();
	};
	class GradeTooLowException : public std::exception { 
			public:
				const char *what() const throw();
	};
	class NotSignedException : public std::exception { 
			public:
				const char *what() const throw();
	};

};
std::ostream & operator<<(std::ostream & os, const AForm & AForm);


#endif
