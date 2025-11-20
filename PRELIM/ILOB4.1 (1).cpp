#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = value;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            top--;
        }
    }

    void getTop() {
        if (top == -1) {
            cout << "The stack is empty!" << endl;
        } else {
            cout << "The element on the top of the stack is " << arr[top] << endl;
        }
    }

    void isEmpty() {
        cout << (top == -1 ? "Stack is EMPTY" : "Stack is NOT EMPTY") << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        getTop();
    }
};

int main() {
    int size;
    cout << "Enter number of max elements for new stack: ";
    cin >> size;

    Stack s(size);
    int choice, value;

    while (true) {
        cout << "Stack Operations:\n";
        cout << "1. PUSH, 2. POP, 3. TOP, 4. isEMPTY, 5. DISPLAY\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "New Value:\n";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.getTop();
                break;
            case 4:
                s.isEmpty();
                break;
            case 5:
                s.display();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}