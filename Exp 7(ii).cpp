#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == NULL) return;

        Node* temp = head;

        // Search for node
        while (temp != NULL && temp->data != value)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Value not found\n";
            return;
        }

        // If node is head
        if (temp == head) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
        }
        else {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display backward
    void displayBackward() {
        if (head == NULL) return;

        Node* temp = head;

        // Move to last node
        while (temp->next != NULL)
            temp = temp->next;

        // Traverse backward
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Forward: ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();

    list.deleteNode(20);

    cout << "After deletion (Forward): ";
    list.displayForward();

    return 0;
}
