#pragma once
#include <cstdint>
#include <vector>

template <typename T>
int64_t binarySearch(const std::vector<T> &data, const T& value) {
    int64_t l = 0, r = data.size();
    while(l < r) {
        int64_t m = l + (r - l) / 2;
        if(value == data)
            return m;
        if(value < data[m])
            r = m;
        else
            l = m + 1;
    }
    return -1;
}
