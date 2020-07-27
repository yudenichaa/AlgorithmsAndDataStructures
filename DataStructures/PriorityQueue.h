#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T, typename Compare = std::less<T>>
class PriorityQueue {
public:
    PriorityQueue(size_t priorityQueueCapacity) :
        data(new T[priorityQueueCapacity]), capacity(priorityQueueCapacity), size(0) { }

    PriorityQueue(const T *initArray, size_t sizeOfInitArray) :
        data(new T[sizeOfInitArray]), capacity(sizeOfInitArray), size(sizeOfInitArray)
    {
        for(size_t i = 0; i < size; ++i)
            data[i] = initArray[i];
        for(size_t i = capacity / 2; i > 0; --i)
            siftDown(i - 1);
    }

    ~PriorityQueue() {
        delete [] data;
    }

    void insert(const T &value) {
        if(size == capacity)
            throw std::runtime_error("priority queue overflow");
        data[size] = value;
        siftUp(size);
        ++size;
    }

    const T& getMax() const {
        if(isEmpty())
            throw std::runtime_error("getMax from empty priority queue");
        return data[0];
    }

    void popMax() {
        if(!isEmpty()) {
            --size;
            std::swap(data[0], data[size]);
            siftDown(0);
        }
    }

    void changeMaxPriority(const T &priority) {
        if(!isEmpty()) {
            data[0] = priority;
            siftDown(0);
        }
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

private:
    void siftUp(size_t index) {
        if(index == 0)
            return;
        size_t parentIndex = parent(index);
        if(Compare()(data[index], data[parentIndex])) {
            std::swap(data[index], data[parentIndex]);
            siftUp(parentIndex);
        }
    }

    void siftDown(size_t index) {
        size_t indexOfChildToSwapWith = index;
        size_t leftChildIndex = firstChild(index);
        if(leftChildIndex < size && Compare()(data[leftChildIndex], data[indexOfChildToSwapWith]))
            indexOfChildToSwapWith = leftChildIndex;
        size_t rightChildIndex = secondChild(index);
        if(rightChildIndex < size && Compare()(data[rightChildIndex], data[indexOfChildToSwapWith]))
            indexOfChildToSwapWith = rightChildIndex;
        if(index != indexOfChildToSwapWith) {
            std::swap(data[index], data[indexOfChildToSwapWith]);
            siftDown(indexOfChildToSwapWith);
        }
    }

    size_t parent(size_t index) const {
        return (index - 1) / 2;
    }

    size_t firstChild(size_t index) const {
        return 2 * index + 1;
    }

    size_t secondChild(size_t index) const {
        return 2 * (index + 1);
    }

private:
    T *data;
    size_t capacity;
    size_t size;
};

