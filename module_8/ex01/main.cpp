#include "Span.hpp"
#include <iostream>

int main()
{
	// try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
		sp.addNumber(11);
	// } catch (Span::FullSpanException e) {
	// 	std::cout << "Exception caugh: " << e.what() << std::endl; 
	// }
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	return 0;
}
