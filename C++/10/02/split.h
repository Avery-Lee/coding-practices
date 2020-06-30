#ifndef GUARD_split_h
#define GUARD_split_h

#include <vector>
#include <string>
#include <algorithm>

bool space(char c);

bool not_space(char c);

std::vector<std::string> split(const std::string& str);

#endif // !GUARD_split_h
