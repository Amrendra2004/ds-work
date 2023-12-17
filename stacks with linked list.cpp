#include <iostream>
using namespace std;
// Node structure representing each element in the linked list
struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Push operation to add an element to the top of the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Pop operation to remove and return the element from the top of the stack
    int pop() {
        if (top) {
            int poppedValue = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << "Popped " << poppedValue << " from the stack." << endl;
            return poppedValue;
        } else {
            cerr << "Stack underflow! Cannot pop from an empty stack." << endl;
            return -1; // Return a sentinel value to indicate an error
        }
    }

    // Peek operation to return the element at the top of the stack without removing it
    int peek() const {
        if (top) {
            return top->data;
        } else {
            cerr << "Stack is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate an error
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
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
