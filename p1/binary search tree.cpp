#include <iostream>
#include <queue>
using namespace std;
// Node structure representing each element in the BST
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the BST
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper function to find the minimum value node in a BST
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a value from the BST
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children, get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    // Helper function to search for a value in the BST and change its value
    TreeNode* searchAndUpdate(TreeNode* node, int x, int y) {
        if (node == nullptr) {
            return node;
        }

        if (x < node->data) {
            node->left = searchAndUpdate(node->left, x, y);
        } else if (x > node->data) {
            node->right = searchAndUpdate(node->right, x, y);
        } else {
            // Node with value x found, update its value to y
            node->data = y;
        }

        return node;
    }

    // Helper function to perform preorder traversal
    void preorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Helper function to perform inorder traversal
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Helper function to perform postorder traversal
    void postorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    // Helper function to calculate the height of the BST
    int calculateHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Delete a value from the BST
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    // Search for a value in the BST and change its value to y
    void searchAndUpdate(int x, int y) {
        root = searchAndUpdate(root, x, y);
    }

    // Display elements of the BST in preorder traversal
    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    // Display elements of the BST in inorder traversal
    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    // Display elements of the BST in postorder traversal
    void displayPostorder() {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }

    // Display elements of the BST in level-by-level traversal
    void displayLevelOrder() {
        if (root == nullptr) {
            return;
        }

        cout << "Level Order Traversal: ";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }

    // Display the height of the BST
    void displayHeight() {
        int height = calculateHeight(root);
        cout << "Height of the BST: " << height << endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "BST after insertion:" << endl;
    bst.displayInorder();

    bst.deleteNode(30);
    cout << "BST after deletion of 30:" << endl;
    bst.displayInorder();

    bst.searchAndUpdate(40, 45);
    cout << "BST after updating value 40 to 45:" << endl;
    bst.displayInorder();

    cout << "BST Traversals:" << endl;
    bst.displayPreorder();
    bst.displayInorder();
    bst.displayPostorder();
    bst.displayLevelOrder();

    bst.displayHeight();

    return 0;
}
