#include <iostream>
using namespace std;
class Stack {
private:
    static const int MAX_SIZE = 100; // Adjust the size based on your requirements
    int array[MAX_SIZE];
    int top;

public:
    // Constructor
    Stack() : top(-1) {}

    // Push operation to add an element to the top of the stack
    void push(int value) {
        if (top < MAX_SIZE - 1) {
            array[++top] = value;
            cout << "Pushed " << value << " onto the stack." << endl;
        } else {
            cerr << "Stack overflow! Cannot push onto a full stack." << endl;
        }
    }

    // Pop operation to remove and return the element from the top of the stack
    int pop() {
        if (top >= 0) {
            int poppedValue = array[top--];
            cout << "Popped " << poppedValue << " from the stack." << endl;
            return poppedValue;
        } else {
            cerr << "Stack underflow! Cannot pop from an empty stack." << endl;
            return -1; // Return a sentinel value to indicate an error
        }
    }

    // Peek operation to return the element at the top of the stack without removing it
    int peek() const {
        if (top >= 0) {
            return array[top];
        } else {
            cerr << "Stack is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate an error
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top of the stack: " << myStack.peek() << endl;

    myStack.pop();
    myStack.pop();

    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    myStack.pop(); // Attempting to pop from an empty stack

    return 0;
}
