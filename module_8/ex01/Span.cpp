#include "Span.hpp"

Span::Span() {}

Span::Span(const Span &src) {
    (void)src;
}

Span::Span(unsigned int n) : maxSize(n) {}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
    (void)rhs;
    return *this;
}

void    Span::addNumber(int n) {
    if (span.size() >= maxSize)
        throw Span::FullSpanException();
    span.push_back(n);
}

const char *Span::FullSpanException::what() const throw() { 
    return ("Sorry sir, the span is full");
}

const char *Span::NotEnoughSpanException::what() const throw() { 
    return ("Sorry sir, there is not enough elements in the span");
}

