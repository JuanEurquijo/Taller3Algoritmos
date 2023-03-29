#ifndef _BOTTOMUP_H_
#define _BOTTOMUP_H_

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>

using bottomup_memory = std::vector<std::vector<int64_t>>;
std::pair<int64_t, bottomup_memory> maxProductBottomUp(std::vector<int64_t> &S);

#endif // _BOTTOMUP_H_
