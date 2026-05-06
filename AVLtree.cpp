#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVL {
public:
    int getHeight(Node* root) {
        if (root == NULL)
            return 0;
        return root->height;
    }

    int getBalance(Node* root) {
        if (root == NULL)
            return 0;
        return getHeight(root->left) - getHeight(root->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* root, int val) {
        if (root == NULL)
            return new Node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        else
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && val < root->left->data)
            return rightRotate(root);

        if (balance < -1 && val > root->right->data)
            return leftRotate(root);

        if (balance > 1 && val > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && val < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main() {
    AVL tree;
    Node* root = NULL;

    int choice, val;

    do {
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = tree.insert(root, val);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 3);

    return 0;
}
