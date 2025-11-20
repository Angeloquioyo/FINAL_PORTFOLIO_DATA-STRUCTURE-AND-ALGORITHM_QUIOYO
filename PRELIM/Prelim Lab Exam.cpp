#include <iostream>
#include <string>


#define MAX_SIZE 100

class ArrayStack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    void push(char c) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top < 0) {
            std::cout << "Stack Underflow" << std::endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return (top < 0);
    }
};


struct Node {
    char data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = NULL; 
    }

    void push(char c) {
        Node* newNode = new Node();
        newNode->data = c;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == NULL) { 
            std::cout << "Stack Underflow" << std::endl;
            return '\0';
        }
        Node* temp = top;
        char data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() {
        return (top == NULL); 
    }
};


bool isPalindrome(const std::string& str) {
    if (str.empty()) {
        return true;
    }

    
    ArrayStack checkStack;
    int i = 0;

   
    while (i < str.length()) {
        checkStack.push(str[i]);
        i++;
    }

    
    i = 0;

    
    while (i < str.length()) {
        if (str[i] != checkStack.pop()) {
            return false;
        }
        i++;
    }

   
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a number or a string to check if it's a palindrome: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "The input \"" << input << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "The input \"" << input << "\" is not a palindrome." << std::endl;
    }

    return 0;
}
