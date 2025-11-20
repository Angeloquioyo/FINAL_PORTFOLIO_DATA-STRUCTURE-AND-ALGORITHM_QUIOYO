#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(char ch) {
        Node* newNode = new Node{ch, top};
        top = newNode;
    }

    char pop() {
        if (isEmpty()) return '\0';
        char ch = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return ch;
    }

    ~StackLinkedList() {
        while (!isEmpty()) pop();
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBalancedLinkedList(const string& expr) {
    StackLinkedList stack;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false;
            char open = stack.pop();
            if (!isMatchingPair(open, ch)) return false;
        }
    }
    return stack.isEmpty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    if (checkBalancedLinkedList(expr)) {
        cout << "Balanced (Linked List)" << endl;
    } else {
        cout << "Not Balanced (Linked List)" << endl;
    }

    cout << "\n--------------------------------" << endl;

    return 0;
}
