#include <iostream>
using namespace std;
// Node structure representing each element in the circular linked list
struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~CircularLinkedList() {
        if (!head) {
            return;
        }

        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        // Delete the head
        delete head;
    }

    // (i) Insert an element x at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head; // Circular reference
        } else {
            newNode->next = head;
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            head = newNode;
        }
    }

    // (ii) Insert an element x at ith position
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cerr << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            insertAtBeginning(value);
            return;
        }

        if (!head) {
            cerr << "List is empty, position should be 0" << endl;
            delete newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current->next != head; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // (iii) Insert an element x at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head; // Circular reference
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    // (iv) Remove an element from the beginning
    void removeFromBeginning() {
        if (!head) {
            cerr << "List is empty" << endl;
            return;
        }

        if (head->next == head) {
            // Only one element in the list
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            Node* temp = head;
            current->next = head->next;
            head = head->next;
            delete temp;
        }
    }

    // (v) Remove an element from ith position
    void removeFromPosition(int position) {
        if (position < 0 || !head) {
            cerr << "Invalid position or list is empty" << endl;
            return;
        }

        if (position == 0) {
            removeFromBeginning();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;
        for (int i = 0; i < position && current->next != head; ++i) {
            previous = current;
            current = current->next;
        }

        if (!current || !previous) {
            cerr << "Invalid position" << endl;
            return;
        }

        previous->next = current->next;
        delete current;
    }

    // (vi) Remove an element from the end
    void removeFromEnd() {
        if (!head) {
            cerr << "List is empty" << endl;
            return;
        }

        if (head->next == head) {
            // Only one element in the list
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            Node* previous = nullptr;
            while (current->next != head) {
                previous = current;
                current = current->next;
            }
            previous->next = head;
            delete current;
        }
    }

    // (vii) Search for an element x and return its pointer
    Node* search(int value) {
        if (!head) {
            return nullptr;
        }

        Node* current = head;
        do {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        } while (current != head);

        return nullptr;
    }

    // (viii) Concatenate two circular linked lists
    void concatenate(CircularLinkedList& otherList) {
        if (!head) {
            head = otherList.head;
        } else if (otherList.head) {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = otherList.head;
            Node* otherCurrent = otherList.head;
            while (otherCurrent->next != otherList.head) {
                otherCurrent = otherCurrent->next;
            }
            otherCurrent->next = head;
        }
        otherList.head = nullptr; // Avoids deleting nodes from the other list in its destructor
    }

    // Display the circular linked list
    void display() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    cout << "Original List: ";
    myList.display();

    myList.insertAtPosition(4, 2);
    myList.removeFromBeginning();
    myList.removeFromPosition(1);

    cout << "Modified List: ";
    myList.display();

    CircularLinkedList otherList;
    otherList.insertAtEnd(7);
    otherList.insertAtEnd(6);
    otherList.insertAtEnd(5);

    cout << "Other List: ";
    otherList.display();

    myList.concatenate(otherList);

    cout << "Concatenated List: ";
    myList.display();

    return 0;
}
