#pragma once
#include <cstddef>
#include <vector>

template <typename T>
void mergeSort(std::vector<T> &data) {
    mergeSortR(data, 0, data.size());
}

template <typename T>
void mergeSortR(std::vector<T> &data, size_t l, size_t r) {
    if(r > l + 1) {
        size_t mid = l + (r - l) / 2;
        mergeSortR(data, l, mid);
        mergeSortR(data, mid, r);
        merge(data, l, mid, r);
    }
}

template <typename T>
void merge(std::vector<T> &data, size_t l, size_t mid, size_t r) {
    std::vector<T> merged(r - l);
    size_t i = l, j = mid, t = 0;
    while(i < mid && j < r) {
        if(data[i] < data[j])
            merged[t++] = data[i++];
        else
            merged[t++] = data[j++];
    }
    while(i < mid)
        merged[t++] = data[i++];
    while(j < r)
        merged[t++] = data[j++];
    for(size_t k = l; k < r; ++k)
        data[k] = merged[k - l];
}
