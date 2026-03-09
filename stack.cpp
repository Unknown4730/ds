#include<iostream>
class Stack {
private:
 int* data;
 int top;
 int capacity;

public:
 Stack(int cap) : data(new int[cap]), top(-1), capacity(cap) {}

 ~Stack() {
 delete[] data;
 }

 bool isEmpty() const {
 return top == -1;
 }

 bool isFull() const {
 return top == capacity -1;
 }

 void push(int value) {
 if (isFull()) {
 std::cout << "Stack overflow\n";
 return;
 }
 data[++top] = value;
 std::cout << "Pushed: " << value << "\n";
 }

 void pop() {
 if (isEmpty()) {
 std::cout << "Stack underflow\n";
 return;
 }
 std::cout << "Popped: " << data[top--] << "\n";
 }

 void peek() const {
 if (isEmpty()) {
 std::cout << "Stack is empty\n";
 return;
 }
 std::cout << "Top: " << data[top] << "\n";
 }

 void display() const {
 if (isEmpty()) {
 std::cout << "Stack is empty\n";
 return;
 }
 std::cout << "Stack elements: ";
 for (int i = top; i >=0; --i) {
 std::cout << data[i];
 if (i !=0) std::cout << " ";
 }
 std::cout << "\n";
 }
};

int main() {
 int capacity;
 std::cout << "Enter stack capacity: ";
 std::cin >> capacity;

 if (capacity <=0) {
 std::cout << "Invalid capacity\n";
 return 0;
 }

 Stack st(capacity);
 int choice;

 do {
 std::cout << "\n1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Is Full\n6. Display\n0. Exit\n";
 std::cout << "Enter choice: ";
 std::cin >> choice;

 switch (choice) {
 case1: {
 int value;
 std::cout << "Enter value: ";
 std::cin >> value;
 st.push(value);
 break;
 }
 case2:
 st.pop();
 break;
 case3:
 st.peek();
 break;
 case4:
 std::cout << (st.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
 break;
 case5:
 std::cout << (st.isFull() ? "Stack is full\n" : "Stack is not full\n");
 break;
 case6:
 st.display();
 break;
 case0:
 std::cout << "Exiting\n";
 break;
 default:
 std::cout << "Invalid choice\n";
 }
 } while (choice !=0);

 return 0;
}