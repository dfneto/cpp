#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T> 
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack&	operator=(const MutantStack &rhs);
		~MutantStack();
		
		//typename é para dizer que é um tipo e não que estou acessando um static member
		//typedef é para criar um alias para um tipo

		// Iterators are not directly part of std::stack itself because std::stack does not expose 
		// the full interface of the underlying container. To get iterators, you need to access 
		// the iterators of the underlying container, which is std::stack<T>::container_type
		typedef typename std::stack<T>::container_type::iterator it;
		// 3. Why is iterator an alias and not a variable of the type std::stack<T>::container_type::iterator?
		// https://chatgpt.com/share/6788ba37-2868-8010-8746-f93ff70beb1c
		
};

#endif
