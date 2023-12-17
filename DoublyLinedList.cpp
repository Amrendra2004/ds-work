#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert_at_beginning(int x) {
        Node* new_node = new Node(x);
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void insert_at_end(int x) {
        Node* new_node = new Node(x);
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void remove_from_beginning() {
        if (head == nullptr) {
            std::cerr << "List is empty" << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // The list is now empty
        }

        delete temp;
    }

    void remove_from_end() {
        if (tail == nullptr) {
            std::cerr << "List is empty" << std::endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // The list is now empty
        }

        delete temp;
    }

    Node* get_head() const {
        return head;
    }

    Node* get_tail() const {
        return tail;
    }
};

int main() {
    DoublyLinkedList myList;

    // Insert elements at the beginning
    myList.insert_at_beginning(5);
    myList.insert_at_beginning(3);
    myList.insert_at_beginning(1);

    // Display the doubly linked list after adding at the beginning
    Node* current = myList.get_head();
    std::cout << "Doubly Linked List after adding at the beginning: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Correctly insert an element at the end
    myList.insert_at_end(7);

    // Display the doubly linked list after removal from the beginning
    current = myList.get_head();
    std::cout << "Doubly Linked List after Insertion at the End: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Remove an element from the beginning
    myList.remove_from_beginning();

    // Display the doubly linked list after removal from the beginning
    current = myList.get_head();
    std::cout << "Doubly Linked List after Removal from the Beginning: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Remove an element from the end
    myList.remove_from_end();

    // Display the doubly linked list after removal from the end
    current = myList.get_tail();
    std::cout << "Doubly Linked List after Removal from the End: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;

    return 0;
}
