#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

int main(void) {
	std::array<int, 5>		arr = {1, 2, 3, 4, 5};
	std::vector<int>		vec = {6, 7, 8, 9, 10};
	std::deque<int>			deq ({11, 12, 13, 14, 15});
	std::forward_list<int>	flist = {16, 17, 18, 19, 20};
	std::list<int>			list = {21, 22, 23, 24, 25};
	const std::list<int>	list2 = {21, 22, 23, 24, 25};

	try {
		auto pos = 0;
		auto itArr = easyfind(arr, 3);
		pos = std::distance(arr.begin(), itArr);
		std::cout << "Num: " << *itArr << " found in array at pos: " << pos << "\n";
		
		auto itVec = easyfind(vec, 9);
		pos = std::distance(vec.begin(), itVec);
		std::cout << "Num: " << *itVec << " found in vector at pos: " << pos << "\n";
		
		auto itDeq = easyfind(deq, 11);
		pos = std::distance(deq.begin(), itDeq);
		std::cout << "Num: " << *itDeq << " found in deque at pos: " << pos << "\n";
		
		auto itFlist = easyfind(flist, 17);
		pos = std::distance(flist.begin(), itFlist);
		std::cout << "Num: " << *itFlist << " found in forward_list at pos: " << pos << "\n";
		
		auto itList = easyfind(list, 25);
		pos = std::distance(list.begin(), itList);
		std::cout << "Num: " << *itList << " found in list at pos: " << pos << "\n";
		
		auto itList2 = easyfind(list2, 30);
		pos = std::distance(list2.begin(), itList2);
		std::cout << "Num: " << *itList2 << " found in list2 at pos: " << pos << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	return (0);
}