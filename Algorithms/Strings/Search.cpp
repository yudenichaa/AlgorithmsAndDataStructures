#include "Algorithms/Strings/Search.h"

std::vector<size_t> searchKMP1(const std::string &text, const std::string & pattern) {
    std::string s = pattern + '$' + text;
    std::vector<size_t> prefixLength = computePrefixes(s);
    std::vector<size_t> positions;
    for(size_t i = 2 * pattern.size(); i < s.size(); ++i)
        if(prefixLength[i] == pattern.size())
            positions.push_back(i - 2 * pattern.size());
    return positions;
}

std::vector<size_t> searchKMP2(const std::string &text, const std::string &pattern) {
    std::vector<size_t> prefixLength = computePrefixes(pattern);
    std::vector<size_t> positions;
    size_t i = 0, j = 0;
    while(i < text.size()) {
        if(text[i] == pattern[j]) {
            ++i;
            ++j;
        }
        if(j == pattern.size()) {
            positions.push_back(i - j);
            j = prefixLength[j - 1];
        }
        if(j < pattern.size() && text[i] != pattern[j]) {
            if(j != 0)
                j = prefixLength[j - 1];
            else
                ++i;
        }
    }
    return positions;
}

std::vector<size_t> computePrefixes(const std::string &pattern) {
    std::vector<size_t> prefixLength(pattern.size());
    prefixLength[0] = 0;
    size_t border = 0;
    for(size_t i = 1; i < pattern.size(); ++i) {
        while(border > 0 && pattern[i] != pattern[border])
            border = prefixLength[border - 1];
        if(pattern[i] == pattern[border])
            ++border;
        prefixLength[i] = border;
    }
    return prefixLength;
}

std::vector<size_t> naiveSearch(const std::string &text, const std::string &pattern) {
    std::vector<size_t> positions;
    if(text.size() < pattern.size())
        return positions;
    for(size_t i = 0, j; i <= text.size() - pattern.size(); ++i) {
        for(j = 0; j < pattern.size(); ++j)
            if(pattern[j] != text[i + j])
                break;
        if(j == pattern.size())
            positions.push_back(i);
    }
    return positions;
}
