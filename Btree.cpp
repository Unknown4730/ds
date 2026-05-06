#include <iostream>
using namespace std;

class BTreeNode {
    int *keys;
    int t;
    BTreeNode **C;
    int n;
    bool leaf;

public:
    BTreeNode(int temp, bool bool_leaf) {
        t = temp;
        leaf = bool_leaf;

        keys = new int[2 * t - 1];
        C = new BTreeNode *[2 * t];

        n = 0;
    }

    void traverse() {
        int i;
        for (i = 0; i < n; i++) {
            if (!leaf)
                C[i]->traverse();
            cout << keys[i] << " ";
        }

        if (!leaf)
            C[i]->traverse();
    }

    void insertNonFull(int k) {
        int i = n - 1;

        if (leaf) {
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }

            keys[i + 1] = k;
            n++;
        }
        else {
            while (i >= 0 && keys[i] > k)
                i--;

            if (C[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1, C[i + 1]);

                if (keys[i + 1] < k)
                    i++;
            }

            C[i + 1]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode *y) {
        BTreeNode *z = new BTreeNode(y->t, y->leaf);
        z->n = t - 1;

        for (int j = 0; j < t - 1; j++)
            z->keys[j] = y->keys[j + t];

        if (!y->leaf) {
            for (int j = 0; j < t; j++)
                z->C[j] = y->C[j + t];
        }

        y->n = t - 1;

        for (int j = n; j >= i + 1; j--)
            C[j + 1] = C[j];

        C[i + 1] = z;

        for (int j = n - 1; j >= i; j--)
            keys[j + 1] = keys[j];

        keys[i] = y->keys[t - 1];

        n++;
    }

    friend class BTree;
};

class BTree {
    BTreeNode *root;
    int t;

public:
    BTree(int temp) {
        root = NULL;
        t = temp;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    void insert(int k) {
        if (root == NULL) {
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        }
        else {
            if (root->n == 2 * t - 1) {
                BTreeNode *s = new BTreeNode(t, false);

                s->C[0] = root;

                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k)
                    i++;

                s->C[i]->insertNonFull(k);

                root = s;
            }
            else
                root->insertNonFull(k);
        }
    }
};

int main() {
    int degree, choice, val;

    cout << "Enter degree of B Tree: ";
    cin >> degree;

    BTree t(degree);

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
                t.insert(val);
                break;

            case 2:
                cout << "Traversal: ";
                t.traverse();
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
