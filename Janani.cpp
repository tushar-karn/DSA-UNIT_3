#include <iostream>
#include <stack>
#include <string>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

std::string infixToPostfix(const std::string& expression) {
    std::stack<char> operatorStack;
    std::string postfix;
    
    for (char ch : expression) {
        if (std::isalnum(ch)) {  // Operand
            postfix += ch;
        } else if (ch == '(') {  // Left parenthesis
            operatorStack.push(ch);
        } else if (ch == ')') {  // Right parenthesis
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();  // Remove the '(' from the stack
        } else if (isOperator(ch)) {  // Operator
            while (!operatorStack.empty() && operatorStack.top() != '(' && precedence(ch) <= precedence(operatorStack.top())) {
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
