#pragma once
#include <vector>
#include <cstddef>
#include <utility>

template <typename T>
void selectionSort(std::vector<T> &data) {
    size_t indexOfMinElement;
    for(size_t i = 0; i + 1 < data.size(); ++i) {
        indexOfMinElement = i;
        for(size_t j = i + 1; j < data.size(); ++j)
            if(data[j] < data[indexOfMinElement])
                indexOfMinElement = j;
        using std::swap;
        swap(data[i], data[indexOfMinElement]);
    }
}
