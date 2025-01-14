#include "Span.hpp"

Span::Span() {}

Span::Span(const Span &src) {
    if (this != &src)
        *this = src;
}

Span &Span::operator=(const Span &rhs) {
    this->vec = rhs.vec;
    this->maxSize = rhs.maxSize;
    return *this;
}

Span::Span(unsigned int n) : maxSize(n) {}

Span::~Span() {}

void    Span::addNumber(int n) {
    if (vec.size() >= maxSize)
        throw std::invalid_argument("Sorry sir, the array is full.");
    vec.push_back(n);
}

int Span::shortestSpan() {
    if (vec.size() <= 1)
        throw::Span::NotEnoughSpanException();
    
    std::sort(vec.begin(), vec.end());
    
    int shortestSpan = vec[1] - vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        int span = vec[i] - vec[i - 1];
        if (span < shortestSpan)
            shortestSpan = span;
    }
    return shortestSpan;
}

int Span::longestSpan() {
    if (vec.size() <= 1)
        throw::Span::NotEnoughSpanException();
    std::sort(vec.begin(), vec.end());
    return vec[vec.size() - 1] - vec[0];
}

const char *Span::NotEnoughSpanException::what() const throw() { 
    return ("Sorry sir, there is not enough elements in the span");
}

