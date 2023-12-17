#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>

class Stack {
private:
    std::stack<double> data;

public:
    void push(double value) {
        data.push(value);
    }

    double pop() {
        if (!data.empty()) {
            double top = data.top();
            data.pop();
            return top;
        } else {
            std::cerr << "Error: Stack is empty" << std::endl;
            return 0; // Return a default value, you may choose to handle this differently
        }
    }

    bool isEmpty() const {
        return data.empty();
    }
};

// Function to evaluate a postfix expression
double evaluatePostfix(const std::string& postfix) {
    Stack stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Convert character to numeric value
        } else if (ch == ' ') {
            // Skip spaces
        } else {
            // Operator encountered
            double operand2 = stack.pop();
            double operand1 = stack.pop();

            switch (ch) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        stack.push(operand1 / operand2);
                    } else {
                        std::cerr << "Error: Division by zero" << std::endl;
                        return 0; // Return a default value, you may choose to handle this differently
                    }
                    break;
                case '^':
                    stack.push(pow(operand1, operand2));
                    break;
                default:
                    std::cerr << "Error: Unknown operator " << ch << std::endl;
                    return 0; // Return a default value, you may choose to handle this differently
            }
        }
    }

    if (!stack.isEmpty()) {
        return stack.pop();
    } else {
        std::cerr << "Error: Stack is empty" << std::endl;
        return 0; // Return a default value, you may choose to handle this differently
    }
}

int main() {
    // Example postfix expression: "3 4 2 * 5 +"
    std::string postfixExpression = "3 4 2 * 5 +";
    double resultPostfix = evaluatePostfix(postfixExpression);
    std::cout << "Result of Postfix Expression: " << resultPostfix << std::endl;

    // Example prefix expression: "+ 5 * 3 2"
    // Note: Prefix expression needs to be read in reverse for evaluation
    std::string prefixExpression = "+ 5 * 3 2";
    std::reverse(prefixExpression.begin(), prefixExpression.end());
    double resultPrefix = evaluatePostfix(prefixExpression);
    std::cout << "Result of Prefix Expression: " << resultPrefix << std::endl;

    return 0;
}
