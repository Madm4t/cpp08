#include "Span.hpp"
#include <iostream>

int main() {
	Span sp = Span(100005);
	try {
		std::cout << "---------- First Test ----------\n";
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try{
		std::cout << "\n---------- Second Test ----------\n";
		sp.addNumbers(100000, 20);
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try{ 
		std::cout << "\n---------- Third Test ----------\n";

		sp.addNumber(30);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try{
		std::cout << "\n---------- Fourth Test ----------\n";
		Span sp2 = Span();

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try{
		std::cout << "\n---------- Fith Test ----------\n";
		Span sp3 = Span(1);
		Span sp4 = sp3;

		sp4.addNumber(5);

		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}

