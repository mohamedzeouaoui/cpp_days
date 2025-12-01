#include "RPN.hpp"

#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

bool RPN::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

long RPN::apply_Op(long a, long b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw std::runtime_error("division by zero");
        return a / b;
    }
    throw std::runtime_error("invalid operator");
}

long RPN::evaluate(const std::string &expr)
{
    std::istringstream iss(expr);
    std::stack<long> st;
    std::string tok;

    while (iss >> tok)
    {
        if (tok.size() == 1 && std::isdigit(tok[0]))
        {
            st.push(static_cast<long>(tok[0] - '0'));
        }
        else if (tok.size() == 1 && isOperator(tok[0]))
        {
            if (st.size() < 2)
                throw std::runtime_error("not enough operands");
            long b = st.top();
            st.pop();
            long a = st.top();
            st.pop();
            st.push(apply_Op(a, b, tok[0]));
        }
        else
            throw std::runtime_error("invalid token");
    }
    if (st.size() != 1)
        throw std::runtime_error("malformed expression");
    return st.top();
}
