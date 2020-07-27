#pragma once
#include <cstddef>
#include <vector>
#include <utility>

template <typename T>
void quickSort(std::vector<T> &data) {
    quickSortR(data, 0, data.size());
}

template <typename T>
void quickSortR(std::vector<T> &data, size_t l, size_t r) {
    if(l < r) {
        size_t pi = partition(data, l, r);
        quickSortR(data, l, pi);
        quickSortR(data, pi + 1, r);
    }
}

template <typename T>
size_t partition(std::vector<T> &data, size_t l, size_t r) {
    T &pivot = data[r - 1];
    size_t i = l;
    for(size_t j = l; j < r - 1; ++j) {
        if(data[j] < pivot) {
            using std::swap;
            swap(data[i], data[j]);
            ++i;
        }
    }
    std::swap(data[i], data[r - 1]);
    return i;
}
