#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push element
void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push element.\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack.\n";
    }
}

// Function to pop element
void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Cannot pop element.\n";
    } else {
        cout << stack[top] << " popped from stack.\n";
        top--;
    }
}

// Function to peek top element
void peek() {
    if (top == -1) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

// Function to display stack
void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
