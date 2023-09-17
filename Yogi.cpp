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

bool isOperand(char ch) {
    return std::isalnum(ch);
}

bool isValidExpression(const std::string& expression) {
    std::stack<char> parenthesesStack;
    
    for (char ch : expression) {
        if (ch == '(') {
            parenthesesStack.push(ch);
        } else if (ch == ')') {
            if (parenthesesStack.empty() || parenthesesStack.top() != '(') {
                return false;
            }
            parenthesesStack.pop();
        }
    }
    
    return parenthesesStack.empty();
}

std::string infixToPostfix(const std::string& expression) {
    if (!isValidExpression(expression)) {
        return "Invalid Expression";
    }
    
    std::stack<char> operatorStack;
    std::string postfix;
    
    for (char ch : expression) {
        if (isOperand(ch)) {
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
    int n;
    std::cin >> n;
    
    std::cin.ignore(); // Consume the newline character
    
    for (int i = 1; i <= n; ++i) {
        std::string infixExpression;
        std::getline(std::cin, infixExpression);
        
        std::string postfixExpression = infixToPostfix(infixExpression);
        std::cout << "Postfix expression " << i << ": " << postfixExpression << std::endl;
    }
    
    return 0;
}
