#include <iostream>
#include <limits>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* topNode;
    int sizeCount;
    int capacity;   // optional limit

public:
    Stack(int cap) : topNode(nullptr), sizeCount(0), capacity(cap) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    bool isFull() const {
        return sizeCount == capacity;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        sizeCount++;

        cout << value << " pushed successfully\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = topNode;
        cout << temp->data << " popped\n";
        topNode = topNode->next;
        delete temp;
        sizeCount--;
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top element: " << topNode->data << endl;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = topNode;
        cout << "Stack elements (top to bottom): ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter stack capacity: ";
    cin >> capacity;

    Stack s(capacity);

    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Is Full\n6. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;

            case 5:
                cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;

            case 6:
                s.display();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}