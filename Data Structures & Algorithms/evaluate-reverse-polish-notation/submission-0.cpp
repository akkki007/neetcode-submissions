#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> s;

        for (const std::string& token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int a = s.top();
                s.pop();

                int b = s.top();
                s.pop();

                if (token == "+")
                    s.push(b + a);
                else if (token == "-")
                    s.push(b - a);
                else if (token == "*")
                    s.push(b * a);
                else
                    s.push(b / a);
            } else {
                s.push(std::stoi(token));
            }
        }

        return s.top();
    }
};