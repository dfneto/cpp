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
        throw std::invalid_argument("Sorry sir, the array is full.");
    span.push_back(n);
}

int Span::shortestSpan() {
    if (span.size() <= 1)
        throw::Span::NotEnoughSpanException();
    
    std::cout << span.begin() << "_" << span.end() << std::endl;
    std::sort(span.begin(), span.end());
    std::cout << span.begin() << "_" << span.end() << std::endl;

    int shortestSpan = INT_MAX;
    for (size_t i = 0; i < span.size(); i++) {
        for (size_t j = 0; j < span.size(); j++) {
            if (i != j && std::fabs(span[i] - span[j]) < shortestSpan)
                shortestSpan = std::fabs(span[i] - span[j]);
        }
    }
    return shortestSpan;
}

int Span::longestSpan() {
    if (span.size() <= 1)
        throw::Span::NotEnoughSpanException();
    return 1;
}

const char *Span::NotEnoughSpanException::what() const throw() { 
    return ("Sorry sir, there is not enough elements in the span");
}

