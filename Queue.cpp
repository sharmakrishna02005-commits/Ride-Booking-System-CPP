#include "Queue.h"
#include <iostream>

// Constructor
Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

// Destructor - Clean up all remaining nodes to prevent memory leaks
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Add passenger to the back of the queue
void Queue::enqueue(Passenger* p) {
    if (p == nullptr) return;
    
    QueueNode* newNode = new QueueNode(p);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

// Remove passenger from the front of the queue
Passenger* Queue::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }
    
    QueueNode* temp = front;
    Passenger* passenger = temp->passenger;
    
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
    size--;
    return passenger;
}

// Peek at the front passenger without removing
Passenger* Queue::peek() const {
    if (isEmpty()) {
        return nullptr;
    }
    return front->passenger;
}

// Check if queue is empty
bool Queue::isEmpty() const {
    return front == nullptr;
}

// Get the current size of the queue
int Queue::getSize() const {
    return size;
}
