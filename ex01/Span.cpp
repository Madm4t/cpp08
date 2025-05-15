#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : _n(0) {
	std::cout << "Defaul Span Constructor called.\n";
}

Span::Span(unsigned int N) : _n(N) {
	std::cout << "Span Constructed of size: " << N << "\n";
}

Span::Span(const Span& other) {
	*this = other;
	std::cout << "Span Copy constructed.\n";
}

Span &Span::operator=(const Span& other) {
	if (this != &other) {
		_n = other._n;
		_span = other._span;
	}
	std::cout << "Span copy constructed\n";
	return (*this);
}

Span::~Span() {
	std::cout << "Span destructor called.\n";
}

void Span::addNumber(int i) {
	if (_span.size() < _n)
		_span.push_back(i);
	else
		throw SpanFullException();
}

void Span::addNumbers(unsigned int count, int i) {
	if (_span.size() + count > _n)
		throw SpanFullException();
	_span.insert(_span.end(), count, i);
}

unsigned int Span::shortestSpan() const {
	if (_span.size() < 2)
		throw NoSpanException();
	std::vector<int> tmp = _span;
	std::sort(tmp.begin(), tmp.end());

	unsigned int minDiff = static_cast<unsigned int>(tmp[1] - tmp[0]);
	for (size_t i = 1; i + 1 < tmp.size(); ++i) {
		unsigned int diff = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

unsigned int Span::longestSpan() const {
	if (_span.size() < 2)
		throw NoSpanException();
	auto min_max = std::minmax_element(_span.begin(), _span.end());
	unsigned int max_span = static_cast<unsigned int>(*min_max.second - *min_max.first);
	return max_span;
}

const char* Span::SpanFullException::what() const throw() {
	return "Span is full";
}

const char* Span::NoSpanException::what() const throw() {
	return "No Span or size too small.\n";
}