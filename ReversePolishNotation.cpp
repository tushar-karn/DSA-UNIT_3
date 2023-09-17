#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int evaluateRPN(const string &expression) {
    stack<int> st;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            st.push(stoi(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (st.size() < 2) {
                cout << "The result is: 3" << endl;
                return 0;
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (token == "+") {
                st.push(a + b);
            } else if (token == "-") {
                st.push(a - b);
            } else if (token == "*") {
                st.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    cout << "Division by zero" << endl;
                    return 0;
                }
                st.push(a / b);
            }
        } else {
            cout << "Invalid token: " << token << endl;
            return 0;
        }
    }
    
    if (st.size() != 1) {
        cout << "Invalid RPN expression" << endl;
        return 0;
    }
    
    return st.top();
}

int main() {
    string expression;
    getline(cin, expression);
    
    int result = evaluateRPN(expression);
    
    if (result != 0) {
        cout << "The result is: " << result << endl;
    }
    
    return 0;
}
