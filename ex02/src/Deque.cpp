
#include "../includes/PmergeMe.hpp"
#include <ctime>

void PmergeMe::bianrySearchDeque(std::vector<int> jacobsthal, std::vector<int> pendant) {
	std::deque<int>::iterator pos = std::lower_bound(_stackD.begin(), _stackD.end(), pendant[0]);;
	_stackD.insert(pos, pendant[0]);
	int i = 0;
	if (pendant.size() != 1) {
		for (std::vector<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); it++) {
			std::deque<int>::iterator pos = std::lower_bound(_stackD.begin(), _stackD.end(), pendant[jacobsthal[i] - 1]);
			_stackD.insert(pos, pendant[jacobsthal[i] - 1]);
			i++;
		}
	}
}

void PmergeMe::SortDeque(std::vector<std::pair<int, int> > array, int oddNumber) {
	
	std::vector<int> pendant;
	for (std::vector<std::pair<int, int> >::iterator it = array.begin(); it != array.end(); it++) {
		_stackD.push_back(it->first);
		pendant.push_back(it->second);
	}
	std::vector<int> jacobsthal = getJacobsthal(pendant.size());

	bianrySearchDeque(jacobsthal, pendant);
	if (oddNumber != -1) {
		std::deque<int>::iterator pos = std::lower_bound(_stackD.begin(), _stackD.end(), oddNumber);;
		_stackD.insert(pos, oddNumber);
	}
	_endD = clock();
}

void PmergeMe::PairDeque() {
	_startD = clock();
	std::vector<std::pair<int, int> > array;
	int oddNumber = -1;
	size_t maxSize = _stackD.size();

	if (_stackD.size() == 1) {
		_endD = clock();
		return ;
	}
	if (_stackD.size() % 2 != 0) {
		oddNumber = _stackD.back();
		_stackD.pop_back();
	}
	for (size_t i = 0; i < maxSize / 2; i++) {
		int n1 = _stackD.back();
		_stackD.pop_back();
		int n2 = _stackD.back();
		_stackD.pop_back();
		if (n1 > n2)
			array.push_back(std::make_pair(n1, n2));
		else
			array.push_back(std::make_pair(n2, n1));
	}
	int len = array.size();
	MergeSort(array, 0, len - 1);
	SortDeque(array, oddNumber);
}