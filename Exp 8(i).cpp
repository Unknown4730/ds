#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed into stack\n";
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << temp->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    // Peek operation
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element is: " << top->data << endl;
        }
    }

    // Check if empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();
    s.display();

    return 0;
}
