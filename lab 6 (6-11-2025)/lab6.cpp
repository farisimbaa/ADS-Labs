//Lab 6: Queue

#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

// Global front and rear pointers
Node* front = nullptr;
Node* rear = nullptr;

// Check if queue is empty
bool isEmpty() {
    return front == nullptr;
}

// Check if queue is full (no more memory)
bool isFull() {
    Node* testNode = new(nothrow) Node;
    if (testNode == nullptr) return true;
    delete testNode;
    return false;
}

// Enqueue: add element to the rear
void enqueue(string value) {
    if (isFull()) {
        cout << "Queue overflow: cannot enqueue '" << value << "'." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Enqueued: " << value << endl;
}

// Dequeue: remove element from the front
void dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow: nothing to dequeue." << endl;
        return;
    }

    Node* temp = front;
    cout << "Dequeued: " << temp->data << endl;

    front = front->next;
    if (front == nullptr) {
        rear = nullptr; // Queue becomes empty
    }

    delete temp;
}

// Peek: view front element
void peek() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

// Display all elements
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue (front -> rear): ";
    Node* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    enqueue("test1");
    enqueue("test2");
    enqueue("test3");

    display();  // Output: test1 test2 test3

    peek();     // Output: Front element: test1
    dequeue();  // Removes test1
    display();  // Output: test2 test3

    cout << (isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
    cout << (isFull() ? "Queue is full" : "Queue is not full") << endl;

    return 0;
}
