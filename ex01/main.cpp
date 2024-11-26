# include "includes/RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of argument\n";
        return 1;
    }

    RPN stack;
    for (int i = 0; argv[1][i]; i++) {
        int num = 0;
        if (argv[1][i] == ' ')
            continue ;
        if (std::isdigit(argv[1][i])) {
            num = std::atoi(&argv[1][i]);
            if (num > 10) {
                std::cerr << "Error: invalid argument\n";
                return 1;
            }
            stack.push(num);
            continue ;
        }
        if ((argv[1][i] == '+' || argv[1][i] == '-'
                || argv[1][i] == '/' ||argv[1][i] == '*') && stack.size() >= 2) {
            std::string new_op(1, argv[1][i]);
            stack.makeOperator(new_op);
            if (stack.empty())
                return 1;
        }
        else {
            std::cerr << "Error: invalid argument\n";
            return 1;
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error: invalid argument\n";
        return 1;
    }
    std::cout << stack.top() << std::endl;
    return 0;
}

