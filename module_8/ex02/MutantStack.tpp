#include "MutantStack.hpp"

template <typename T> 
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T> 
MutantStack<T>::~MutantStack() {}

template <typename T> 
MutantStack<T>::MutantStack(const MutantStack &src) : 
    std::stack<T>::stack(src) {}

template <typename T> 
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack &rhs) {
    if (this != &rhs)
        this->c = rhs.c;
    return *this;
}

// The inline keyword in this implementation is used to suggest 
// to the compiler that the function's code should be inserted 
// directly at each point where the function is called, instead 
/// of generating a separate function call. This can improve 
// performance by avoiding the overhead of a function call, 
// especially for small, frequently used functions like begin() and end().
template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}
