#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span {
	private:
		Span();
		std::vector<int>	span;
		unsigned int		maxSize;

	public:
		Span(const Span &src);
		Span(unsigned int n);
		~Span();
		
		Span&		operator=(const Span &rhs);
		void		addNumber(int n);
		int			shortestSpan();
		int			longestSpan();

	class FullSpanException : public std::exception { 
    	public:
			const char *what() const throw();
	};
	class NotEnoughSpanException : public std::exception { 
    	public:
			const char *what() const throw();
	};
};

#endif
