#ifndef REVERSE_POLISH_NOTATION
#define REVERSE_POLISH_NOTATION

#include	<iostream> 	//cout, cerr
#include 	<stack>	
#include	<sstream>	//istringstream
#include	<limits>	//numeric_limits
#include 	<cstdlib>	//atof
#include 	<stdexcept>  // Required for standard exceptions

//TODO: transformar a entrada em ""
//TODO: fiz um pouco do parser da entrada, mas não trato somente números por exemplo
//DONE: criar a stask e começar a adicionar elementos a ela

class ReversePolishNotation {
	private:
		ReversePolishNotation(const ReversePolishNotation &src);
		ReversePolishNotation&		operator=(const ReversePolishNotation &rhs);
		bool 						isNumber(const std::string &s);
		bool 						isOperator(const std::string &s);
		bool						checkRPNInput(char *);
		double 						makeTheMath(char *);
		double						applyOperator(double, double, char);

		std::stack<double>	stack;
		char* 				inputWithNoSpaces;


	public:
		ReversePolishNotation();
		~ReversePolishNotation();
		double		calculateRPN(char *);
		
};

#endif
