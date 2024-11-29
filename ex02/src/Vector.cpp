
#include "../includes/PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iterator>
#include <vector>

void PmergeMe::bianrySearchVector(std::vector<int> jacobsthal, std::vector<int> pendant) {
	std::vector<int>::iterator pos = std::lower_bound(_stackV.begin(), _stackV.end(), pendant[0]);;
	_stackV.insert(pos, pendant[0]);
	if (pendant.size() != 1)
		for (size_t i = 0; i < pendant.size(); i++) {
			if (static_cast<size_t>(jacobsthal[i]) <= pendant.size()) {
				std::vector<int>::iterator pos = std::lower_bound(_stackV.begin(), _stackV.end(), pendant[jacobsthal[i] - 1]);
				_stackV.insert(pos, pendant[jacobsthal[i] - 1]);
			}
		}
}

void PmergeMe::sortVector(std::vector<std::pair<int, int> > array, int oddNumber) {
	
	std::vector<int> pendant;
	for (std::vector<std::pair<int, int> >::iterator it = array.begin(); it != array.end(); it++) {
		std::cout << "init pendant\n";
		_stackV.push_back(it->first);
		pendant.push_back(it->second);
		std::cout << "pendant end\n";
	}
	std::vector<int> jacobsthal = getJacobsthal(pendant.size());
	std::cout << "jacob ok\n";

	bianrySearchVector(jacobsthal, pendant);
	std::cout << "binary done\n";
	if (oddNumber != -1) {
		std::vector<int>::iterator pos = std::lower_bound(_stackV.begin(), _stackV.end(), oddNumber);;
		_stackV.insert(pos, oddNumber);
	}
	_endV = clock();
	getStackAfter();
}

void PmergeMe::PairVector() {
	_startV = clock();
	std::vector<std::pair<int, int> > array;
	int oddNumber = -1;
	size_t maxSize = _stackV.size();

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
		std::cout << "ok pair\n";
			
	}
	int len = array.size();
	std::cout << len << std::endl;
	MergeSort(array, 0, len - 1);
	std::cout << "merge ok\n";
	sortVector(array, oddNumber);
}
