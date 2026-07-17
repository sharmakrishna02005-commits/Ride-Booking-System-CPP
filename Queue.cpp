#include "Queue.h"
#include <iostream>


Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}


Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}


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


Passenger* Queue::peek() const {
    if (isEmpty()) {
        return nullptr;
    }
    return front->passenger;
}


bool Queue::isEmpty() const {
    return front == nullptr;
}


int Queue::getSize() const {
    return size;
}
