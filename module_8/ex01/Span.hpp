#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
	private:
		Span();
		std::vector<int>	vec;
		unsigned int		maxSize;

	public:
		Span(const Span &src);
		Span(unsigned int n);
		~Span();
		
		Span&		operator=(const Span &rhs);
		void		addNumber(int n);
		template <typename it>
		void		addManyNumbers(it begin, it end);
		int			shortestSpan();
		int			longestSpan();

	class NotEnoughSpanException : public std::exception { 
    	public:
			const char *what() const throw();
	};
};

template <typename it>
void	Span::addManyNumbers(it begin, it end) {
	//distance calculates the number of elements between two iterators.
	if (std::distance(begin, end) >  maxSize)
        throw std::invalid_argument("Sorry sir, the array is full.");
	// The vector insert() function can also insert elements from a range into the vector at given index. This range can be any STL container or an array.
	// pos– Iterator to the position where range is to be inserted.
	// first– Iterator to the first element in the range from which the elements are to be inserted.
	// last– Iterator to the element one place after the last element in the range.

	vec.insert(vec.end(), begin, end);
}

#endif
