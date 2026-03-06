#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int value;
    if (rear == MAX - 1) {
        cout << "Queue Overflow\n";
    } else {
        cout << "Enter value to enqueue: ";
        cin >> value;
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        cout << "Element inserted successfully\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
    } else {
        cout << "Deleted element: " << queue[front] << endl;
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nQueue Operations Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
