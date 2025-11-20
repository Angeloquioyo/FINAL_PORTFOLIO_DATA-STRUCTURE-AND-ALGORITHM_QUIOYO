#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class StackArray {
private:
    char arr[MAX];
    int top;

public:
    StackArray() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char ch) {
        if (!isFull()) arr[++top] = ch;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBalancedArray(const string& expr) {
    StackArray stack;
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
    getline(cin, expr); // Supports full-line input

    if (checkBalancedArray(expr)) {
        cout << "Balanced (Array)" << endl;
    } else {
        cout << "Not Balanced (Array)" << endl;
    }

    cout << "\n--------------------------------" << endl;

    return 0;
}
