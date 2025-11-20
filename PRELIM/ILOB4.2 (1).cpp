#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

Node *head = nullptr;

void push(int newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

int pop() {
    if (head == nullptr) {
        cout << "Stack Underflow." << endl;
        return -1;
    } else {
        Node *temp = head;
        int tempVal = temp->data;
        head = head->next;
        delete temp;
        return tempVal;
    }
}

void Top() {
    if (head == nullptr) {
        cout << "Stack is Empty." << endl;
    } else {
        cout << "Top of Stack: " << head->data << endl;
    }
}

void display() {
    cout << "Stack elements (top to bottom):" << endl;
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
	
    push(1);
    cout << "After the first PUSH, top of stack is: ";
    Top();

    push(5);
    cout << "After the second PUSH, top of stack is: ";
    Top();

    pop();
    cout << "After the first POP operation, top of stack is: ";
    Top();

    pop();
    cout << "After the second POP operation, top of stack is: ";
    Top();

    pop();

    display();

    return 0;
}