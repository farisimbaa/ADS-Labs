//Lab 5: Stack

#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

// Global top pointer
Node* top = nullptr;

// Check if stack is empty
bool isEmpty() {
    return top == nullptr;
}

// Check if stack is full (no more memory)
bool isFull() {
    Node* testNode = new(nothrow) Node;
    if (testNode == nullptr)
        return true;
    delete testNode;
    return false;
}

// Push: add element to top
void push(string value) {
    if (isFull()) {
        cout << "Stack overflow: cannot push '" << value << "'." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed: " << value << endl;
}

// Pop: remove top element
void pop() {
    if (isEmpty()) 
    {
        cout << "Stack underflow: nothing to pop." << endl;
        return;
    }
    Node* temp = top;
    cout << "Popped: " << temp->data << endl;
    top = top->next;
    delete temp;
}

// Peek: view top element
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top element: " << top->data << endl;
    }
}

// Display all elements
void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top -> bottom): ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    push("test1");
    push("test2");
    push("test3");

    display();  // Output: test3 test2 test1

    peek();     // Output: Top element: test3
    pop();      // Removes test3
    display();  // Output: test2 test1

    cout << (isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
    cout << (isFull() ? "Stack is full" : "Stack is not full") << endl;

    return 0;
}
