#include "Span.hpp"
#include <iostream>
#include <ctime>

int main()
{
	//Subject test
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(15);
		// sp.addNumber(116);
		std::cout << "The shortest distance is: " << sp.shortestSpan() << std::endl;
		std::cout << "The longest distance is: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caugh: " << e.what() << std::endl; 
	}
	std::cout << std::endl;

    //Normal Span, no exception
    try { 
        Span span(10);

        for (int i = 0; i < 10; ++i) {
            span.addNumber(i);
        }
        int shortest = span.shortestSpan();
        int longest = span.longestSpan();
        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

	//Normal Span, no exception, 50000 elements
    try { 
        Span span(50000);

        for (int i = 1; i <= 50000; ++i) {
            span.addNumber(i);
        }

        int shortest = span.shortestSpan();
        int longest = span.longestSpan();
        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

	//Normal Span, test addNumbers with iterator and random numbers
	try {
		Span span(10000);
		std::srand(std::time(NULL));
		std::vector<int> randomNumbers;
        //Eu crio u vetor randomNumbers com 10.000 elementos
		for (int i = 0; i <= 10000; ++i)
			randomNumbers.push_back(rand() % 10000);
        //agora vou adicionar todos os 10k elementos a spain apenas passando um iterador do inicio e do fim de randomNumbers
		span.addManyNumbers(randomNumbers.begin(), randomNumbers.end());
		int shortest = span.shortestSpan();
        int longest = span.longestSpan();

        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
