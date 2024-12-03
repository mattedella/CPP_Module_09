# include "includes/PmergeMe.hpp"
#include <cctype>
#include <cstddef>

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
	}
	else {
		if (argv[1][0] == '\0') {
			std::cerr << "Error: all argument must be a positive number\n";
			return 1;
		}
		std::string string = argv[1];
		for(size_t i = 0; string.size() > 0; i++) {
			while (string[0] == ' ')
				string.erase(string.begin());
			if (!std::isdigit(string[0])) {
				std::cerr << "Error: all argument must be a positive number\n";
				return 1;
			}
			std::string Sum = string.substr(0, string.find(' '));
			int num = std::atoi(Sum.c_str());
			sort.addToStack(num);
			for (size_t i = 0; i < Sum.size(); i++) {
				string.erase(string.begin());
			}
		}
	}
	sort.getStackBefore();
	sort.PairVector();
	sort.PairDeque();
	sort.getStackAfter();
	return 0;
}
