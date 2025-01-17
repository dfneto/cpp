#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> 
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack&	operator=(const MutantStack &rhs);
		~MutantStack();
		
		// typedef é para criar um alias para um tipo
		// typename é para dizer que é um tipo e não que estou acessando um static member
		// ex: Class::variable

		// Iterators are not directly part of std::stack itself because std::stack does not expose 
		// the full interface of the underlying container. To get iterators, you need to access 
		// the iterators of the underlying container, which is std::stack<T>::container_type
		// You're defining iterator as a new name (alias) for the type 
		// std::stack<T>::container_type::iterator. iterator is a variable of the 
		// type std::deque<int>::iterator (assuming std::deque is the default underlying container).
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();

		
};

#include "MutantStack.tpp"

#endif
