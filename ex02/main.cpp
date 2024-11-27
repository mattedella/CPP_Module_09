# include "includes/PmergeMe.hpp"
#include <cstdlib>
#include <cctype>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: wrong number of argument\n";
        return 1;
    }

    PmergeMe sort;
    if (argc > 2) {
        for (int i = 1; argv[i]; i++) {
            for (int j = 0; argv[i][j]; j++) {
                if (!std::isdigit(argv[i][j])) {
                    std::cerr << "Error: all argument must be a positive number\n";
                    return 1;
                }
            }
            int num = std::atoi(argv[i]);
            sort.addToStack(num);
        }
        sort.getStackBefore();
        sort.PairVector();
    }
}

