#include <iostream>
using namespace std;
// Node structure representing each element in the circular linked list
struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* rear; // Pointer to the rear of the circular linked list

public:
    // Constructor
    CircularQueue() : rear(nullptr) {}

    // Destructor to free memory
    ~CircularQueue() {
        if (!isEmpty()) {
            Node* current = rear->next;
            while (current != rear) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            delete rear; // Delete the last node (rear)
        }
    }

    // Enqueue operation to add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear; // Circular reference
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    // Dequeue operation to remove and return the element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cerr << "Queue underflow! Cannot dequeue from an empty queue." << endl;
            return -1; // Return a sentinel value to indicate an error
        }

        int dequeuedValue;
        if (rear->next == rear) {
            // Only one element in the queue
            dequeuedValue = rear->data;
            delete rear;
            rear = nullptr;
        } else {
            Node* front = rear->next;
            dequeuedValue = front->data;
            rear->next = front->next;
            delete front;
        }

        cout << "Dequeued " << dequeuedValue << " from the queue." << endl;
        return dequeuedValue;
    }

    // Peek operation to return the element at the front of the queue without removing it
    int peek() const {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate an error
        }

        return rear->next->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return rear == nullptr;
    }
};

int main() {
    CircularQueue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front of the queue: " << myQueue.peek() << endl;

    myQueue.dequeue();
    myQueue.dequeue();

    cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    myQueue.dequeue(); // Attempting to dequeue from an empty queue

    return 0;
}
