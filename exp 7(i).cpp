#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == NULL) return;

        // If head node is to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Linked List: ";
    list.display();

    list.deleteNode(20);
    cout << "After deletion: ";
    list.display();

    return 0;
}
