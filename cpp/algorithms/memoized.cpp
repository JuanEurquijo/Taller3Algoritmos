#include "memoized.h"
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

int64_t maxProductMemoizedAux(memoized_memory &M, std::vector<int64_t> &S,
                              int64_t i, int64_t j) {

  // Caso base memoizado
  if (M[i][j].has_value()) {
    return M[i][j].value();
  }

  // Caso Base
  if (i + 1 == j) {
    M[i][j] = S[i];
    return M[i][j].value();
  }

  // Llamados a casos base
  auto max_a = maxProductMemoizedAux(M, S, i + 1, j);
  auto max_b = maxProductMemoizedAux(M, S, i, j - 1);

  // Hallar el producto
  int64_t product = 1;
  for (int64_t idx = i; idx < j; idx++) {
    product *= S[idx];
  }

  // Hallar el máximo entre todas las soluciones
  int64_t max_product = std::max({max_a, max_b, product});

  if (product >= max_product) {
    M[i][j] = product;
  } else if (max_a >= max_product) {
    M[i][j] = max_a;
  } else {
    M[i][j] = max_b;
  }

  return M[i][j].value();
}

std::pair<int64_t, memoized_memory>
maxProductMemoized(std::vector<int64_t> &S) {
  // Fill memory
  memoized_memory M{};
  for (size_t i = 0; i < S.size(); i++) {
    M.push_back(std::vector<std::optional<int64_t>>());
    for (size_t j = 0; j < S.size() + 1; j++)
      M[i].push_back(std::nullopt);
  }

  maxProductMemoizedAux(M, S, 0, S.size());
  return std::make_pair(M[0][S.size()].value(), M);
}