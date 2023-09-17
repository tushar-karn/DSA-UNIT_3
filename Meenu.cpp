#include <iostream>
#include <stack>
#include <string>

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

std::string infixToPostfix(const std::string& expression) {
    std::stack<char> operatorStack;
    std::string postfix;
    
    for (char ch : expression) {
        if (std::isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operatorStack.push(ch);
        } else if (ch == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Remove the '(' from the stack
        } else if (isOperator(ch)) {
            while (!operatorStack.empty() && operatorStack.top() != '(' && precedence(operatorStack.top()) >= precedence(ch)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }
    
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    
    return postfix;
}

int main() {
    std::string infixExpression;
    std::cin >> infixExpression;
    
    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Postfix expression: " << postfixExpression << std::endl;
    
    return 0;
}
