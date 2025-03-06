#ifndef REVERSE_POLISH_NOTATION
#define REVERSE_POLISH_NOTATION

#include	<iostream> 	//cout, cerr
#include 	<stack>	
#include	<sstream>	//istringstream
#include	<limits>	//numeric_limits
#include 	<cstdlib>	//atof
#include 	<stdexcept>  // Required for standard exceptions

class ReversePolishNotation {
	private:
		ReversePolishNotation(const ReversePolishNotation &src);
		ReversePolishNotation&		operator=(const ReversePolishNotation &rhs);
		bool 						isNumber(const std::string &s);
		bool 						isOperator(const std::string &s);
		void						checkRPNInput(char *);
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
