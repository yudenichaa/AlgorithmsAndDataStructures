#pragma once
#include <string>
#include <vector>

std::vector<size_t> searchKMP1(const std::string &text, const std::string & pattern);
std::vector<size_t> searchKMP2(const std::string &text, const std::string &pattern);
std::vector<size_t> computePrefixes(const std::string &pattern);
std::vector<size_t> naiveSearch(const std::string &text, const std::string &pattern);
