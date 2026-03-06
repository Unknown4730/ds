#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = rear = NULL;
    }

    // Enqueue operation
    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << x << " enqueued into queue\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " dequeued from queue\n";
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Peek operation
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element is: " << front->data << endl;
        }
    }

    // Check if empty
    bool isEmpty() {
        return front == NULL;
    }

    // Display queue
    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();
    q.display();

    return 0;
}
