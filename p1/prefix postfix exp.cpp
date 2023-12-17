#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int performOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                cerr << "Error: Division by zero." << endl;
                exit(1);
            }
        case '^':
            return static_cast<int>(pow(operand1, operand2));
        default:
            cerr << "Error: Invalid operator." << endl;
            exit(1);
    }
}

int evaluatePostfix(const string& postfixExpression) {
    stack<int> operandStack;

    istringstream iss(postfixExpression);
    string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            // If the token is an operand (numeric value), push it onto the stack
            operandStack.push(stoi(token));
        } else if (isOperator(token[0])) {
            // If the token is an operator, pop operands from the stack, perform the operation,
            // and push the result back onto the stack
            if (operandStack.size() < 2) {
                cerr << "Error: Insufficient operands for operator " << token << endl;
                exit(1);
            }
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = performOperation(token[0], operand1, operand2);
            operandStack.push(result);
        } else {
            cerr << "Error: Invalid token in the expression." << endl;
            exit(1);
        }
    }

    // The final result should be at the top of the stack
    if (operandStack.size() == 1) {
        return operandStack.top();
    } else {
        cerr << "Error: Invalid expression." << endl;
        exit(1);
    }
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression (operands and operators separated by spaces): ";
    getline(cin, postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
