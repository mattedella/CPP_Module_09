
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <bits/types/timer_t.h>
#include <ctime>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cstddef>
#include <iomanip>

class PmergeMe {

    private:
        std::vector<int>    _stackV;
        std::deque<int>     _stackD;
        clock_t             _startV;
        clock_t             _endV;
        clock_t             _startD;
        clock_t             _endD;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copy);

        PmergeMe& operator=(const PmergeMe& copy);

        void    addToStack(int num);
        void    getStackBefore();
        void    getStackAfter();
        int**   SortPair(int** array);
        void    Merge(std::vector<std::pair<int, int> >& array, int left, int mid, int right);
        void    MergeSort(std::vector<std::pair<int, int> >& array, int left, int right);
        std::vector<int>    getJacobsthal(int maxSize);

        void PairVector();
        void sortVector(std::vector<std::pair<int, int> > array, int oddNumber);
        void bianrySearchVector(std::vector<int> jacobsthal, std::vector<int> pendant);
        
        void PairDeque();
        void SortDeque(std::vector<std::pair<int, int> > array, int oddNumber);
        void bianrySearchDeque(std::vector<int> jacobsthal, std::vector<int> pendant);


        ~PmergeMe();
};

#endif