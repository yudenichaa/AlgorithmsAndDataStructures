#pragma once
#include <vector>
#include <cstddef>
#include <utility>

template <typename T>
void bubbleSort(std::vector<T> &data) {
    bool sorted = false;
    for(size_t i = 0; i + 1 < data.size() && !sorted; ++i) {
        sorted = true;
        for(size_t j = data.size() - 1; j > 0; --j) {
            if(data[j] < data[j - 1]) {
                sorted = false;
                using std::swap;
                swap(data[j], data[j - 1]);
            }
        }
    }
}

