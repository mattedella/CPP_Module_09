
#include "../includes/RPN.hpp"

int RPN::getOperand(std::string& op) {
    const std::string oper[4] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++) {
        if (op == oper[i])
            return i;
    }
    return -1;
}

void RPN::makeOperator(std::string& op) {
    int n = 0;
    int n1 = top();
    pop();
    int n2 = top();
    pop();
    int ope = getOperand(op);
    switch (ope) {
        case 0:
            n = n2 + n1;
            break;
        case 1:
            n = n2 - n1;
            break;
        case 2:
            n = n2 * n1;
            break;
        case 3:
            if (n1 == 0) {
                std::cerr << "division per 0 is impossible\n";
                return ;
            }
            n = n2 / n1;
            break;
        default:
            std::cerr << "Unespected behavior\n";
            return ;

    }
    push(n);
}