#ifndef MINHEAP_H
#define MINHEAP_H

#include "Driver.h"
#include <vector>

struct HeapNode {
    Driver* driver;
    double distance;

    HeapNode(Driver* d, double dist) : driver(d), distance(dist) {}
};

class MinHeap {
private:
    std::vector<HeapNode> heap;

    // Helper functions to maintain heap properties
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Constructor
    MinHeap();

    // Destructor
    ~MinHeap();

    // Heap operations
    void insert(Driver* driver, double distance);
    Driver* extractMin();
    Driver* getMin() const;
    bool isEmpty() const;
    int getSize() const;
    void clear();
};

#endif // MINHEAP_H
