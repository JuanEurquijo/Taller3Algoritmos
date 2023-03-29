#ifndef _MEMOIZED_H_
#define _MEMOIZED_H_

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>

using memoized_memory = std::vector<std::vector<std::optional<int64_t>>>;
std::pair<int64_t, memoized_memory> maxProductMemoized(std::vector<int64_t> &S);

#endif // _MEMOIZED_H_
