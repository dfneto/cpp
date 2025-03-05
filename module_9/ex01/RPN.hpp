#ifndef REVERSE_POLISH_NOTATION
#define REVERSE_POLISH_NOTATION

#include	<iostream> 	//cout, cerr
#include 	<stack>	
#include	<sstream>	//istringstream

//TODO: criar a stask e começar a adicionar elementos a ela

class ReversePolishNotation {
	private:
		ReversePolishNotation(const ReversePolishNotation &src);
		ReversePolishNotation&		operator=(const ReversePolishNotation &rhs);
		bool 						isNumber(const std::string &s);
		bool 						isOperator(const std::string &s);

		std::stack<std::string> stack;


	public:
		ReversePolishNotation();
		~ReversePolishNotation();
		bool	checkRPNInput(int argc, char* argv[]);
		
};

#endif
