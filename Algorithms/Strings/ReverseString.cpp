#include "Algorithms/Strings/ReverseString.h"

void reverseStringWithXor(std::string &s) {
    for(size_t i = 0, j = s.size(); i + 1 < j; ++i, --j) {
        s[i] ^= s[j - 1];
        s[j - 1] ^= s[i];
        s[i] ^= s[j - 1];
    }
}

void reverseStringWithSwap(std::string &s) {
    for(size_t i = 0, j = s.size(); i + 1 < j; ++i, --j)
        std::swap(s[i], s[j - 1]);
}
