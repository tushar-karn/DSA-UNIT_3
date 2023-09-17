#include <iostream>
#include <stack>
#include <string>
#include <cctype>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> stack;
    
    for (char ch : infix) {
        if (std::isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();  // Remove the '(' from the stack
        } else if (isOperator(ch)) {
            while (!stack.empty() && stack.top() != '(' && precedence(stack.top()) >= precedence(ch)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    
    return postfix;
}

int main() {
    std::string infixExpression;
    std::getline(std::cin, infixExpression);
    
    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << postfixExpression << std::endl;
    
    return 0;
}
