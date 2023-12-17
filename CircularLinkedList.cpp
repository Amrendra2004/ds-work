#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int x) {
        Node* new_node = new Node(x);
        if (head == nullptr) {
            head = new_node;
            new_node->next = head;  // Make it circular
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = new_node;
            new_node->next = head;  // Make it circular
        }
    }

    void remove(int x) {
        if (head == nullptr) {
            std::cerr << "List is empty" << std::endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // Find the node to remove
        while (current->data != x) {
            if (current->next == head) {
                std::cerr << "Element not found in the list" << std::endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        // Remove the node
        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            head = current->next;  // Update head if removing the first node
        }

        delete current;
    }

    Node* search(int x) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;
        do {
            if (current->data == x) {
                return current;
            }
            current = current->next;
        } while (current != head);

        return nullptr;  // Element not found
    }

    Node* get_head() const {
        return head;
    }
};

int main() {
    CircularLinkedList myList;

    // Insert elements
    myList.insert(5);
    myList.insert(3);
    myList.insert(1);

    // Display the initial circular linked list
    Node* current = myList.get_head();
    std::cout << "Initial Circular Linked List: ";
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != myList.get_head());
    std::cout << std::endl;

    

    // Add an element at the beginning
    myList.insert(7);

    // Display the circular linked list after adding an element
    current = myList.get_head();
    std::cout << "Circular Linked List after Adding an element: ";
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != myList.get_head());
    std::cout << std::endl;
 
 // Search for an element
    int searchValue = 3;
    Node* foundNode = myList.search(searchValue);
    if (foundNode != nullptr) {
        std::cout << "Element " << searchValue << " found in the list." << std::endl;
    } else {
        std::cout << "Element " << searchValue << " not found in the list." << std::endl;
    }

    // Remove an element
    int removeValue = 3;
    myList.remove(removeValue);

    // Display the circular linked list after removal
    current = myList.get_head();
    std::cout << "Circular Linked List after Removal: ";
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != myList.get_head());
    std::cout << std::endl;

    return 0;
}
