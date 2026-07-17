#ifndef QUEUE_H
#define QUEUE_H

#include "Passenger.h"

struct QueueNode {
    Passenger* passenger;
    QueueNode* next;

    QueueNode(Passenger* p) : passenger(p), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;

public:
    
    Queue();

    
    ~Queue();

    
    void enqueue(Passenger* p);
    Passenger* dequeue();
    Passenger* peek() const;
    bool isEmpty() const;
    int getSize() const;
};

#endif 
