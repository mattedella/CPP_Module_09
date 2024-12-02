
#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) : _stackV(copy._stackV), _stackD(copy._stackD) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy) {
		_stackD = copy._stackD;
		_stackV = copy._stackV;
	}

	return *this;
}

void PmergeMe::addToStack(int num) {
	_stackD.push_back(num);
	_stackV.push_back(num);
}

void PmergeMe::getStackBefore() {
	std::cout << "Before : ";
	for (size_t i = 0; i < _stackD.size(); i++)
		std::cout << _stackD[i] << " ";
	std::cout << "\n\n";
}

void PmergeMe::getStackAfter() {
	std::cout << "After : ";
	for (size_t i = 0; i < _stackV.size(); i++)
		std::cout << _stackV[i] << " ";
	std::cout << "\n\n";
	double elapsed_timeV = (double)(_endV - _startV) / CLOCKS_PER_SEC;
	double elapsed_timeD = (double)(_endD - _startD) / CLOCKS_PER_SEC;
	std::cout << "time to process a range of " << _stackV.size()
		<< " element with std::vector : ";
	std::cout << std::fixed << std::setprecision(5) << elapsed_timeV << " us\n";
	std::cout << "time to process a range of " << _stackD.size() << " element with std::deque : ";
		std::cout << std::fixed << std::setprecision(5) << elapsed_timeD << " us\n";

}

void PmergeMe::Merge(std::vector<std::pair<int, int> >& array, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<std::pair<int, int> > L(n1), R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (L[i].first <= R[j].first) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		array[k] = L[i];
		k++;
		i++;
	}
	while (j < n2) {
		array[k] = R[j];
		j++;
		k++;
	}
}

void PmergeMe::MergeSort(std::vector<std::pair<int, int> >& array, int left, int right) {
	if (left >= right)
		return ;
	
	int mid = left + (right - left) / 2;
	MergeSort(array, left, mid);
	MergeSort(array, mid + 1, right);
	Merge(array, left, mid, right);
}

std::vector<int> PmergeMe::getJacobsthal(int maxSize) {
	std::vector<int> jacobsthal;
	std::vector<int> reverseJacob;
	std::vector<int> sortSequence;
	int P0 = 1;
	int P1 = 3;
	int j = 0, i = 1;
	jacobsthal.push_back(P0);
	jacobsthal.push_back(P1);
	for (int i = 2; jacobsthal[i - 1] < maxSize; i++) {
		int x = jacobsthal[i - 1] + (2 * jacobsthal[i - 2]);
		jacobsthal.push_back(x);
		j++;
	}
	while (jacobsthal[i - 1] < maxSize) {
		if (jacobsthal[i] > maxSize) {
			jacobsthal[i] = maxSize;
		}
		j = jacobsthal[i] - 1;
		sortSequence.push_back(jacobsthal[i]);
		while (j > jacobsthal[i - 1]) {
			sortSequence.push_back(j);
			j--;
		}
		i++;
	}
	return sortSequence;
}

PmergeMe::~PmergeMe() {}
