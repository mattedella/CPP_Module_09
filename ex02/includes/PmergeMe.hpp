
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <utility>
#include <vector>

class PmergeMe {

    private:
        std::vector<int>    _stackV;
        std::deque<int>     _stackD;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copy);

        PmergeMe& operator=(const PmergeMe& copy);

        void addToStack(int num);
        void getStackBefore();
        void getStackAfter();
        int** SortPair(int** array);
        void Merge(std::vector<std::pair<int, int> >& array, int left, int mid, int right);
        void MergeSort(std::vector<std::pair<int, int> >& array, int left, int right);

        void PairVector();
        void sortVector(std::vector<std::pair<int, int> > array, int oddNumber);
        
        void PairDeque();
        void SortDeque(int* arrayA, int* arrayB);


        ~PmergeMe();
};

#endif