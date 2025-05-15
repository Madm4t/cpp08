#pragma once
#include <algorithm>
#include <stdexcept>

struct NotFoundException : std::exception {
	const char* what() const noexcept override {
		return "easyfind: number not found inside the container";
	}
};

template<typename T>
typename T::iterator easyfind(T& container, int num)
{
	auto it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int num)
{
	auto it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw NotFoundException();
	return it;
}