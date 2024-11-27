
#include "../includes/PmergeMe.hpp"
#include <algorithm>
#include <filesystem>
#include <utility>
#include <vector>

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
    std::cout << "Before deque: ";
    for (size_t i = 0; i < _stackD.size(); i++)
        std::cout << _stackD[i] << " ";
    std::cout << '\n';
    std::cout << "Before vector: ";
    for (size_t i = 0; i < _stackV.size(); i++)
        std::cout << _stackV[i] << " ";
    std::cout << '\n';
}

void PmergeMe::getStackAfter() {
    std::cout << "After deque: ";
    for (size_t i = 0; i < _stackD.size(); i++)
        std::cout << _stackD[i] << " ";
    std::cout << '\n';
    std::cout << "After vector: ";
    for (size_t i = 0; i < _stackV.size(); i++)
        std::cout << _stackV[i] << " ";
    std::cout << '\n';
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

void PmergeMe::sortVector(std::vector<std::pair<int, int> > array, int oddNumber) {
    for (std::vector<std::pair<int, int> >::iterator it = array.begin(); it != array.end(); ++it) {
        _stackV.push_back(it->first);
    }
    (void)oddNumber;
    std::cout << "vector sorted\n";
}

void PmergeMe::PairVector() {
    std::vector<std::pair<int, int> > array;
    int oddNumber = -1, maxSize = _stackV.size();
    (void)maxSize;

    if (_stackV.size() % 2 != 0) {
        oddNumber = _stackV.back();
        _stackV.pop_back();
    }

    for (int i = 0; _stackV.size(); i++) {
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
    // std::cout << "prima merge sort: ";
    // for (std::vector<std::pair<int, int> >::iterator it = array.begin(); it != array.end(); ++it) {
    //     std::cout << "(" << it->first << "," << it->second << ") ";
    // }
    // std::cout << std::endl;
    MergeSort(array, 0, len - 1);
    // std::cout << "dopo merge sort: ";
    // for (std::vector<std::pair<int, int> >::iterator it = array.begin(); it != array.end(); ++it) {
    //     std::cout << "(" << it->first << "," << it->second << ") ";
    // }
    sortVector(array, oddNumber);
    getStackBefore();
}

PmergeMe::~PmergeMe() {}