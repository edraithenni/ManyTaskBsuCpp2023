#pragma once

#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

inline int EvaluateExpression(const std::string& expression) {
    std::stack<int> stack;
    std::vector<std::string> newstrings;
    size_t pos = 0;
    size_t pos1 = 0;

    while ((pos = expression.find(' ', pos1)) != std::string::npos) {
        newstrings.push_back(expression.substr(pos1, pos - pos1));
        pos1 = pos + 1;
    }
    newstrings.push_back(expression.substr(pos1));
    int a1 = 0;
    int a2 = 0;

    for (const auto& i : newstrings) {
        if ((i != "+") && (i != "-") && (i != "*")) {
            stack.push(stoi(i));
        } else {
            a1 = stack.top();
            stack.pop();
            a2 = stack.top();
            stack.pop();
            if (i == "+") {
                stack.push(a1 + a2);
            } else if (i == "*") {
                stack.push(a1 * a2);
            } else if (i == "-") {
                stack.push(a2 - a1);
            }
        }
    }
    const int res = stack.top();

    return res;
}
