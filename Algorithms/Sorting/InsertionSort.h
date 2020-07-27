#pragma once
#include <vector>
#include <cstddef>

template <typename T>
void insertionSort(std::vector<T> &data) {
    size_t i, j;
    for(i = 1; i < data.size(); ++i) {
        j = i;
        T key = data[i];
        while(j != 0 && key < data[j - 1]) {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = key;
    }
}
