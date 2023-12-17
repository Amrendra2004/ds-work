#include <iostream>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteRecursive(Node* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        } else {
            // Node with only one child or no child
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteRecursive(current->right, temp->data);
        }

        return current;
    }

    Node* searchRecursive(Node* current, int value) {
        if (current == nullptr || current->data == value) {
            return current;
        }

        if (value < current->data) {
            return searchRecursive(current->left, value);
        }

        return searchRecursive(current->right, value);
    }

    void displayTreeUtil(Node* root) {
        if (root != nullptr) {
            displayTreeUtil(root->left);
            std::cout << root->data << " ";
            displayTreeUtil(root->right);
        }
    }

    void preorderRecursive(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

    void inorderRecursive(Node* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            std::cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    void postorderRecursive(Node* node) {
        if (node != nullptr) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value) != nullptr;
    }

    void displayPreorder() {
        std::cout << "Preorder Traversal: ";
        preorderRecursive(root);
        std::cout << std::endl;
    }

    void displayInorder() {
        std::cout << "Inorder Traversal: ";
        inorderRecursive(root);
        std::cout << std::endl;
    }

    void displayPostorder() {
        std::cout << "Postorder Traversal: ";
        postorderRecursive(root);
        std::cout << std::endl;
    }

    void displayTree() {
        std::cout << "Binary Search Tree Elements after removal: ";
        displayTreeUtil(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Display initial elements
    bst.displayTree();

    // Display in different traversals
    bst.displayPreorder();
    bst.displayInorder();
    bst.displayPostorder();

    // Search for an element
    int searchValue = 40;
    std::cout << "Search for " << searchValue << ": " << (bst.search(searchValue) ? "Found" : "Not Found") << std::endl;

    // Remove an element
    int removeValue = 30;
    bst.remove(removeValue);

    // Display elements after removal
    bst.displayTree();

    // Display in different traversals after removal
    bst.displayPreorder();
    bst.displayInorder();
    bst.displayPostorder();

    return 0;
}
