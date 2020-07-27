#pragma once
#include <cstddef>
#include <vector>

template <typename T>
void heapSort(std::vector<T> &data) {
    std::vector<T> priorityQueue(data);
    for(size_t i = data.size() / 2; i > 0; --i)
        siftDown(priorityQueue, i - 1);
    for(size_t i = 0, j = data.size() - 1; i < data.size(); ++i, --j) {
        data[i] = priorityQueue[0];
        using std::swap;
        swap(priorityQueue[0], priorityQueue[j]);
        siftDown(priorityQueue, 0, j);
    }
    delete [] priorityQueue;
}

template <typename T>
void siftDown(std::vector<T> &data, size_t index) {
    size_t indexToSwapWith = index;
    size_t leftChildIndex = 2 * index + 1;
    if(leftChildIndex < data.size() && data[leftChildIndex] < data[indexToSwapWith])
        indexToSwapWith = leftChildIndex;
    size_t rightChildIndex = 2 * (index + 1);
    if(rightChildIndex < data.size() && data[rightChildIndex] < data[indexToSwapWith])
        indexToSwapWith = rightChildIndex;
    if(indexToSwapWith != index) {
        std::swap(data[index], data[indexToSwapWith]);
        siftDown(data, indexToSwapWith);
    }
}

