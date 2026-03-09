#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node*& head, Node*& tail, int data) {
    Node* newNode = createNode(data);

    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteAtBeginning(Node*& head, Node*& tail) {
    if (head == NULL && tail == NULL) {
        cout << "List is already empty" << endl;
        return;
    }

    Node* temp = head;

    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    } else {
        head = NULL;
        tail = NULL;
    }

    delete temp;
}

void displayList(Node* head) {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void inputList(Node*& head, Node*& tail) {
    string input;
    cout << "Enter elements separated by spaces: ";
    cin.ignore();
    getline(cin, input);

    istringstream iss(input);
    int data;

    while (iss >> data) {
        insertAtEnd(head, tail, data);
    }

    cout << "List created successfully." << endl;
}

int main() {
    Node* head = NULL; 
    Node* tail = NULL;
    int choice;

    while (true) {
        //menu
        cout << "\nDoubly Linked List Operations" << endl;
        cout << "1. Input List" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete from Beginning" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid integer." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                inputList(head, tail);
                break;

            case 2:
                int data;
                cout << "Enter data to insert at the end: ";
                if (!(cin >> data)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid integer." << endl;
                    continue;
                }
                insertAtEnd(head, tail, data);
                break;

            case 3:
                deleteAtBeginning(head, tail);
                break;

            case 4:
                displayList(head);
                break;

            case 5:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}