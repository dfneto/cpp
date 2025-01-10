#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class NotFoundException : public std::exception { 
    public:
        const char *what() const throw() {
            return "Sorry sir, element not found :/";
        }
};

template <typename T> 
int easyfind(T &a, int b) { 
    typename T::iterator it; //estou criando um iterador do tipo T parecido com std::vector<int>::iterator it
    for (it = a.begin(); it != a.end(); it++) {
        if (*it == b)
            return *it;
    }
    throw NotFoundException();
}

#endif
