#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert_at_beginning(int x) {
        Node* new_node = new Node(x);
        new_node->next = head;
        head = new_node;
    }

    void insert_at_position(int i, int x) {
        if (i == 0) {
            insert_at_beginning(x);
            return;
        }

        Node* new_node = new Node(x);
        Node* current = head;

        for (int j = 0; j < i - 1; ++j) {
            if (current == nullptr) {
                std::cerr << "Index out of range" << std::endl;
                return;
            }
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    void remove_at_beginning() {
        if (head == nullptr) {
            std::cerr << "List is empty" << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void remove_at_position(int i) {
        if (i == 0) {
            remove_at_beginning();
            return;
        }

        Node* current = head;

        for (int j = 0; j < i - 1; ++j) {
            if (current == nullptr || current->next == nullptr) {
                std::cerr << "Index out of range" << std::endl;
                return;
            }
            current = current->next;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    Node* search(int x) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == x) {
                return current;
            }
            current = current->next;
        }

        return nullptr; // Element not found
    }

    Node* get_head() const {
        return head;
    }
};

int main() {
    SinglyLinkedList myList;

    // Insert elements at the beginning
    myList.insert_at_beginning(5);
    myList.insert_at_beginning(3);
    myList.insert_at_beginning(1);

    // Display the initial linked list
    Node* current = myList.get_head();
    std::cout << "Initial Linked List: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Search for an element
    int searchValue = 3;
    Node* foundNode = myList.search(searchValue);
    if (foundNode != nullptr) {
        std::cout << "Element " << searchValue << " found in the list." << std::endl;
    } else {
        std::cout << "Element " << searchValue << " not found in the list." << std::endl;
    }

    // Display the linked list before adding at position 1
    std::cout << "Linked List before adding at Position 1: ";
    current = myList.get_head();
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Insert an element at position 1 (0-indexed)
    myList.insert_at_position(1, 2);

    // Display the linked list after adding at position 1
    current = myList.get_head();
    std::cout << "Linked List after adding at Position 1: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;

    
    }
    std::cout << std::endl;
// Remove an element from the beginning
    myList.remove_at_beginning();

    current = myList.get_head();
    std::cout << "Linked List after Removal from the Beginning: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

      // Remove an element from position 2 (0-indexed)
    int removeIndex = 2;
    myList.remove_at_position(removeIndex);

    // Display the linked list after removal
    current = myList.get_head();
    std::cout << "Linked List after Removal at Position " << removeIndex << ": ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
