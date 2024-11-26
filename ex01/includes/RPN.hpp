#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <stack>
#include <cctype>

class RPN : public std::stack<int> {

    public:
        int getOperand(std::string& op);
        void makeOperator(std::string& op);
};

#endif