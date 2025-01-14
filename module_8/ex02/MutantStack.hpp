#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T> 
class MutantStack {
	private:
		std::vector<int>	vec;
		unsigned int		maxSize;

	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack(unsigned int n);
		~MutantStack();
		
		MutantStack&		operator=(const MutantStack &rhs);
		template <typename it>
		void		addManyNumbers(it begin, it end);
};

template <typename it>
void	MutantStack::addManyNumbers(it begin, it end) {
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
