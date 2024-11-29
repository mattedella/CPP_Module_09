# include "includes/PmergeMe.hpp"
#include <cstdlib>
#include <cctype>

int main(int argc, char **argv) {
	if (argc == 1) {
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
		// sort.PairDeque();
		// sort.getStackAfter();
	}
	else {
		std::string Snum;
		int i = 0;
		while (argv[1][i]) {
			while (argv[1][i] == ' ')
				i++;
			if (!std::isdigit(argv[1][i])) {
				std::cerr << "Error: all argument must be a positive number\n";
				return 1;
			}
			while (argv[1][i] != ' ' || argv[1][i] != '\0') {
				std::cout << "conver string ";
				std::string addNum(1, argv[1][i]);
				Snum += addNum;
				i++;
			}
			int num = std::atoi(Snum.c_str());
			sort.addToStack(num);
			i++;
		}
	}
	sort.getStackBefore();
	sort.PairVector();
	return 0;
}
