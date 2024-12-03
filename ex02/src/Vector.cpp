
#include "../includes/PmergeMe.hpp"

void PmergeMe::bianrySearchVector(std::vector<int> jacobsthal, std::vector<int> pendant) {
	std::vector<int>::iterator pos = std::lower_bound(_stackV.begin(), _stackV.end(), pendant[0]);;
	_stackV.insert(pos, pendant[0]);
	int i = 0;
	if (pendant.size() != 1) {
		for (std::vector<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); it++) {
			std::vector<int>::iterator pos = std::lower_bound(_stackV.begin(), _stackV.end(), pendant[jacobsthal[i] - 1]);
			_stackV.insert(pos, pendant[jacobsthal[i] - 1]);
			i++;
		}
	}
}

void PmergeMe::sortVector(std::vector<std::pair<int, int> > array, int oddNumber) {
	
	std::vector<int> pendant;
	for (std::vector<std::pair<int, int> >::iterator it = array.begin(); it != array.end(); it++) {
		_stackV.push_back(it->first);
		pendant.push_back(it->second);
	}
	std::vector<int> jacobsthal = getJacobsthal(pendant.size());

	bianrySearchVector(jacobsthal, pendant);
	if (oddNumber != -1) {
		std::vector<int>::iterator pos = std::lower_bound(_stackV.begin(), _stackV.end(), oddNumber);;
		_stackV.insert(pos, oddNumber);
	}
	_endV = clock();
}

void PmergeMe::PairVector() {
	_startV = clock();
	std::vector<std::pair<int, int> > array;
	int oddNumber = -1;
	size_t maxSize = _stackV.size();

	if (_stackV.size() == 1) {
		_endV = clock();
		return ;
	}
	if (_stackV.size() % 2 != 0) {
		oddNumber = _stackV.back();
		_stackV.pop_back();
	}
	for (size_t i = 0; i < maxSize / 2; i++) {
		int n1 = _stackV.back();
		_stackV.pop_back();
		int n2 = _stackV.back();
		_stackV.pop_back();
		if (n1 > n2)
			array.push_back(std::make_pair(n1, n2));
		else
			array.push_back(std::make_pair(n2, n1));
	}
	int len = array.size();
	MergeSort(array, 0, len - 1);
	sortVector(array, oddNumber);
}
