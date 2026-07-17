#include "MinHeap.h"
#include <algorithm>


MinHeap::MinHeap() {}


MinHeap::~MinHeap() {}


void MinHeap::heapifyUp(int index) {
    if (index == 0) return;

    int parentIndex = (index - 1) / 2;
    if (heap[index].distance < heap[parentIndex].distance) {
        std::swap(heap[index], heap[parentIndex]);
        heapifyUp(parentIndex);
    }
}


void MinHeap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < static_cast<int>(heap.size()) && heap[leftChild].distance < heap[smallest].distance) {
        smallest = leftChild;
    }

    if (rightChild < static_cast<int>(heap.size()) && heap[rightChild].distance < heap[smallest].distance) {
        smallest = rightChild;
    }

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}


void MinHeap::insert(Driver* driver, double distance) {
    if (driver == nullptr) return;
    heap.push_back(HeapNode(driver, distance));
    heapifyUp(heap.size() - 1);
}


Driver* MinHeap::extractMin() {
    if (isEmpty()) return nullptr;

    Driver* minDriver = heap[0].driver;
    heap[0] = heap.back();
    heap.pop_back();

    if (!isEmpty()) {
        heapifyDown(0);
    }

    return minDriver;
}


Driver* MinHeap::getMin() const {
    if (isEmpty()) return nullptr;
    return heap[0].driver;
}


bool MinHeap::isEmpty() const {
    return heap.empty();
}


int MinHeap::getSize() const {
    return static_cast<int>(heap.size());
}


void MinHeap::clear() {
    heap.clear();
}
