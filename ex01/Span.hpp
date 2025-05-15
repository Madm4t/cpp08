#pragma once
#include <vector>
#include <exception>

class Span {
private:
	unsigned int _n;
	std::vector<int> _span;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span &operator=(const Span& other);
	~Span();

	void addNumber(int i);
	void addNumbers(unsigned int count, int i);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	struct SpanFullException : std::exception {
		const char* what() const throw();
	};
	struct NoSpanException : std::exception {
		const char* what() const throw();
	};
};