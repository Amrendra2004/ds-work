#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        return (node != nullptr) ? node->height : 0;
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int getBalanceFactor(Node* node) {
        return (node != nullptr) ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* rotateLeft(Node* y) {
        Node* x = y->right;
        Node* T2 = x->left;

        x->left = y;
        y->right = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateRight(Node* x) {
        Node* y = x->left;
        Node* T2 = y->right;

        y->right = x;
        x->left = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* balance(Node* node) {

        updateHeight(node);


        int balanceFactor = getBalanceFactor(node);

      
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }

      
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }

        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node; 
    }

   
    Node* insert(Node* node, int value) {
      
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            
            return node;
        }

        return balance(node);
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node found, perform deletion
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = (node->left != nullptr) ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr) {
            return node;
        }

        return balance(node);
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}


    ~AVLTree() {
        while (root != nullptr) {
            root = deleteNode(root, root->data);
        }
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    bool search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true; 
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false; 
    }

    void display() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avlTree;

    avlTree.insert(30);
    avlTree.insert(20);
    avlTree.insert(40);
    avlTree.insert(10);
    avlTree.insert(25);

    cout << "Initial AVL Tree:" << endl;
    avlTree.display();

    avlTree.remove(20);

    cout << "AVL Tree after removing 20:" << endl;
    avlTree.display();

    return 0;
}
