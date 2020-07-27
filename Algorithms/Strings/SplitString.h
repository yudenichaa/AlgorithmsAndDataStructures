#pragma once
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> splitString(const std::string &str, char separator);
std::vector<std::string_view> splitStringView(std::string_view str, char separator);
